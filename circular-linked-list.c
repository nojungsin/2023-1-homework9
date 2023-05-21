#include<stdio.h>
#include<stdlib.h>


typedef struct Node {//이중 연결 리스트 구조체 선언
   int key;
   struct Node* llink;
   struct Node* rlink;
} listNode;


int initialize(listNode** h);
int freeList(listNode* h);//원형 연결 리스트의 노드들 free시키기
int insertLast(listNode* h, int key);//연결 리스트의 맨 마지막에 노드 삽입
int deleteLast(listNode* h);//연결 리스트의 맨 마지막 노드 삭제
int insertFirst(listNode* h, int key);//연결 리스트의 맨 처음에 노드 삽입
int deleteFirst(listNode* h);//연결 리스트의 맨 처음 노드 삭제
int invertList(listNode* h);//연결 리스트의 순서 역순으로 바꾸기

int insertNode(listNode* h, int key);//노드 삽입
int deleteNode(listNode* h, int key);//노드 삭제

void printList(listNode* h);//리스트의 key값들 차례대로 출력



int main()
{
   char command;//입력받을 명령어 저장할 char형 변수 command
   int key;//입력받은 key값 저장해놓을 int형 변수 key
   listNode* headnode=NULL;//listNode형 포인터 변수 headnode의 값 NULL로 초기화

   do{
      printf("----------------------------------------------------------------\n");
      printf("                  Doubly Circular Linked List                   \n");
      printf("----------------------------------------------------------------\n");
      printf(" Initialize    = z           Print         = p \n");
      printf(" Insert Node   = i           Delete Node   = d \n");
      printf(" Insert Last   = n           Delete Last   = e\n");
      printf(" Insert First  = f           Delete First  = t\n");
      printf(" Invert List   = r           Quit          = q\n");
      printf("----------------------------------------------------------------\n");

      printf("Command = ");//Command값 입력받기
      scanf(" %c", &command);//입력받은 Command값 변수 command에 저장

      switch(command) {//입력받은 command종류에 따라 다르게 실행
      case 'z': case 'Z'://z나 Z를 입력받은 경우
         initialize(&headnode);//리스트 초기화
         break;
      case 'p': case 'P'://p나 P를 입력받은 경우
         printList(headnode);//리스트의 key값들 차례대로 출력
         break;
      case 'i': case 'I'://i나 I를 입력받은 경우
         printf("Your Key = ");//key값 입력받기
         scanf("%d", &key);//입력받은 key값 변수 key에 저장
         insertNode(headnode, key);//key값을 가지는 노드를 리스트에 삽입
         break;
      case 'd': case 'D'://d나 D를 입력받은 경우
         printf("Your Key = ");//key값 입력받기
         scanf("%d", &key);//입력받은 key값 변수 key에 저장
         deleteNode(headnode, key);//key값을 가지는 노드를 리스트에서 삭제
         break;
      case 'n': case 'N'://n이나 N을 입력받은 경우
         printf("Your Key = ");//key값 입력받기
         scanf("%d", &key);//입력받은 key값 변수 key에 저장
         insertLast(headnode, key);//리스트의 마지막에 key값을 가지는 노드 삽입
         break;
      case 'e': case 'E'://e나 E를 입력받은 경우
         deleteLast(headnode);//리스트의 마지막 노드 삭제
         break;
      case 'f': case 'F'://f나 F를 입력받은 경우
         printf("Your Key = ");//key값 입력받기
         scanf("%d", &key);//입력받은 key값 변수 key에 저장
         insertFirst(headnode, key);//key값을 가지는 노드를 리스트의 맨 처음에 삽입
         break;
      case 't': case 'T'://t나 T를 입력받은 경우
         deleteFirst(headnode);//리스트의 첫 번째 노드 삭제
         break;
      case 'r': case 'R'://r이나 R을 입력받은 경우
         invertList(headnode);//리스트의 순서를 역순으로 바꾸기
         break;
      case 'q': case 'Q'://q나 Q를 입력받은 경우
         freeList(headnode);//리스트의 노드들 다 해제시키기
         break;
      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");//이외의 것들을 입력받은 경우에는 Concentration! 출력
         break;
      }

   }while(command != 'q' && command != 'Q');//q나 Q를 입력받은 경우 loop종료

   return 1;
}


int initialize(listNode** h) {
   if(*h != NULL)//빈 리스트가 아닐 경우
      freeList(*h);//리스트의 노드들 다 free 시키기

   *h = (listNode*)malloc(sizeof(listNode));//headNode초기화시키기
   (*h)->rlink = *h;//자기 자신을 가리키게 하는 주소값 넣기
   (*h)->llink = *h;//자기 자신을 가리키게 하는 주소값 넣기
   (*h)->key = -9999;//key값으로 임의의 값 -9999넣기
   return 1;
}


int freeList(listNode* h){//리스트의 노드들 다 해제시키기
    if(h->rlink == h)//리스트에 노드가 하나밖에 없을 경우
   {
      free(h);//유일한 노드 해제시키기
      return 1;
   }

   listNode* p = h->rlink;//free시킬 때 쓸 포인터 변수 p 생성하고 첫 노드의 rlink에 들어있는 값 넣기

   listNode* prev = NULL;//free시킬 때 쓸 다른 포인터 변수 prev생성하고 NULL값으로 선언
   while(p != NULL && p != h) {//p가 다시 첫 번째 노드를 가리킬 때까지 반복
      prev = p;
      p = p->rlink;
      free(prev);
   }
   free(h);
   return 0;
}


void printList(listNode* h) {//리스트에 있는 노드들의 key값 차례대로 출력
   int i = 0;
   listNode* p;

   printf("\n---PRINT\n");

   if(h == NULL) {//리스트가 비어있을 경우
      printf("Nothing to print....\n");
      return;
   }

   p = h->rlink;

   while(p != NULL && p != h) {//p가 다시 첫 번째 노드로 돌아올 때까지 p가 가리키는 노드들의 key값 출력
      printf("[ [%d]=%d ] ", i, p->key);
      p = p->rlink;
      i++;
   }
   printf("  items = %d\n", i);//item개수 i값 출력으로 얻기


   /* print addresses */
   printf("\n---checking addresses of links\n");
   printf("-------------------------------\n");
   printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

   i = 0;
   p = h->rlink;
   while(p != NULL && p != h) {//p가 다시 첫 번째 노드로 돌아올 때까지 거쳐가는 모든 노드들의 값 다 출력
      printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
      p = p->rlink;
      i++;
   }

}


int insertLast(listNode* h, int key) {//리스트의 마지막에 노드 삽입
    if (h == NULL) return -1;

   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key = key;
   node->rlink = NULL;
   node->llink = NULL;

   if (h->rlink == h) //리스트에 노드가 없을 경우
   {
      h->rlink = node;
      h->llink = node;
      node->rlink = h;
      node->llink = h;
   } else {//리스트에 노드가 있을 경우
      h->llink->rlink = node;//마지막 노드의 rlink에 노드 주소값 넣기
      node->llink = h->llink;//node의 rlink에 마지막 노드의 주소값 넣기
      h->llink = node;//h의 llink에 node의 주소값 넣기
      node->rlink = h;//node의 rlink에 h주소값 넣어서 다시 처음으로 돌아오게 하기
   }

   return 1;
}


int deleteLast(listNode* h) {
    if (h->llink == h || h == NULL)//리스트에 노드가 존재하지 않을 경우
	{
		printf("nothing to delete.\n");
		return 1;
	}

	listNode* nodetoremove = h->llink;//노드 삭제할 때 쓸 포인터 변수 nodetoremove 값 h의 llink값으로 초기화

	nodetoremove->llink->rlink = h;//nodetoremove의 왼쪽 노드의 rlink값 h로 변경
	h->llink = nodetoremove->llink;//h의 llink값 nodetoremove의 왼쪽 노드로 변경

	free(nodetoremove);//nodetoremove가 가리키는 리스트의 마지막 노드 free 시키기
    
    return 1;
}


int insertFirst(listNode* h, int key) {
    listNode* node = (listNode*)malloc(sizeof(listNode));//key값을 가지는 노드 생성
	node->key = key;
	node->rlink = NULL;
	node->llink = NULL;


	node->rlink = h->rlink;//리스트의 첫 번째에 노드 n 삽입하기
	h->rlink->llink = node;
	node->llink = h;
	h->rlink = node;


	return 1;
}


int deleteFirst(listNode* h) {
    if (h == NULL || h->rlink == h)//리스트에 노드가 존재하지 않을 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* nodetoremove = h->rlink;//h의 rlink가 가리키는 값 저장할 포인터 변수 nodetroremove생성

	nodetoremove->rlink->llink = h;//nodetoremove의 가리키는 노드의 오른쪽 노드의 llink값이 h를 가리키게 하기
	h->rlink = nodetoremove->rlink;//h의 rlink값이 nodetoremove의 오른쪽 노드 가리키게 하기

	free(nodetoremove);//nodetoremove free시키기

	return 1;

}


int invertList(listNode* h) {//리스트의 순서 역순으로 바꾸기
    if(h->rlink == h || h == NULL) {//리스트에 노드가 없을 경우
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->rlink;//h의 rlink값을 가지는 포인터 변수 n 생성
	listNode *trail = h;//h를 가리키는 포인터 변수 trail생성
	listNode *middle = h;//h를 가리키는 포인터 변수 middle생성

	h->llink = h->rlink;//h의 llink가 h의 rlink가 가리키는 값 가지게 하기

	while(n != NULL && n != h){//리스트의 모든 노드들을 거치면서 노드들이 가리키는 llink와 rlink값 서로 바꿔서 순서 역순으로 변경
		trail = middle;
		middle = n;
		n = n->rlink;
		middle->rlink = trail;
		middle->llink = n;
	}

	h->rlink = middle;

	return 0;

}



int insertNode(listNode* h, int key) {//노드를 리스트에 삽입할 경우
    if(h == NULL) return -1;//headNode가 없을 경우

	listNode* node = (listNode*)malloc(sizeof(listNode));//key값을 가지는 새로운 노드 생성
	node->key = key;
	node->llink = node->rlink = NULL;

	if (h->rlink == h)//리스트에 노드가 없을 경우
	{
		insertFirst(h, key);
		return 1;
	}

	listNode* n = h->rlink;//h의 rlink값을 저장할 포인터 변수 n 생성

	while(n != NULL && n != h) {//n이 리스트의 모든 노드들 검사하기
		if(n->key >= key) {//n이 가리키는 노드의 key값이 key값보다 크거나 같은 경우
			if(n == h->rlink) {//n이 가리키는 노드가 첫 번째 노드일 경우
				insertFirst(h, key);
			} else { //그외의 경우
				node->rlink = n;
				node->llink = n->llink;
				n->llink->rlink = node;
				n->llink = node;
			}
			return 0;
		}

		n = n->rlink;
	}

	insertLast(h, key);//마지막 노드까지 검사를 했음에도 key값보다 크거나 같은 값을 key값으로 가지는 노드가 없을 경우
	return 0;
}


int deleteNode(listNode* h, int key) {
    if (h->rlink == h || h == NULL)//리스트에 노드가 없을 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->rlink;//h의 rlink값을 가지는 포인터 n 생성

	while(n != NULL && n != h) {//리스트의 노드들을 처음부터 끝까지 검사하기
		if(n->key == key) {//n이 가리키는 노드의 key값과 찾고있는 key값이 일치할 경우
			if(n == h->rlink) { //첫 번째 노드의 key값이 key값과 일치할 경우
				deleteFirst(h);
			} else if (n->rlink == h){ //마지막 노드의 key값이 key값과 일치할 경우
				deleteLast(h);
			} else { //그외의 경우
				n->llink->rlink = n->rlink;
				n->rlink->llink = n->llink;
				free(n);
			}
			return 0;
		}

		n = n->rlink;//n이 현재 가리키는 노드의 key값이 찾고있는 key값이 아닌 경우 현재 노드의 오른쪽으로 이동
	}

	printf("cannot find the node for key = %d\n", key);//마지막 노드까지 모든 노드들의 key값을 검사했음에도 key값에 일치하는 노드를 찾지 못했을 경우
	return 0;
}
