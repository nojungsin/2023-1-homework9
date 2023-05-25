#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;//key값 입력받을 변수
	struct node *left;//왼쪽 자식 노드 주소값 저장할 노드형 포인터 변수 ledt
	struct node *right;//오른쪽 자식 노드 주소값 저장할 노드형 포인터 변수 right
} Node;

int initializeBST(Node** h);

void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL
	
	printf("[----- [윤혜준] [2022041021] -----]"); 

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);//실행할 명령 입력받고 command변수에 저장

		switch(command) {//command변수에 입력받은 값에 따라 다르게 실행
        case 'z': case 'Z'://z나 Z 입력받을 경우 tree 초기화
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
        case 'n': case 'N'://n이나 N 입력받을 경우 tree에 key값을 가지는 노드 적절한 위치에 삽입
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D'://d나 D 입력받을 경우 tree에 key값을 가지는 노드 삭제
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F'://f나 F를 입력받을 경우 찾고싶은 key값을 가지고 있는 노드의 주소 출력하기
			printf("Your Key = ");//key값 입력받기
			scanf("%d", &key);
			ptr = searchIterative(head, key);//입력받은 key값을 가지는 노드의 주소 출력
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);//key값을 가지는 노드를 찾았을 경우 그 위치 출력
			else
				printf("\n Cannot find the node [%d]\n", key);//찾지 못했을 경우 찾지 못함 메시지 출력
			break;
		case 's': case 'S'://s나 S 입력받을 경우
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);//key값을 가지는 노드 tree에서 찾기
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);//찾으면 출력
			else
				printf("\n Cannot find the node [%d]\n", key);//못 찾았으면 못 찾았다는 메세지 출력
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);//LVR순회
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);//VLR순회
			break;
		case 't': case 'T':
			postorderTraversal(head->left);//LRV순회
			break;
		default://명령어로 그외 값들을 입력받은 경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');//명령어로 q나 Q 입력받은 경우 loop 탈출

	return 1;
}

int initializeBST(Node** h) {
	if(*h != NULL)//tree가 비어있지 않을 경우, tree 다 비우기
		freeBST(*h);

	*h = (Node*)malloc(sizeof(Node));//headnode생성
	(*h)->left = NULL;
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}


void inorderTraversal(Node* ptr)
{
	if(ptr) {//LVR순회
		inorderTraversal(ptr->left);
		printf(" [%d] ", ptr->key);
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr)
{
	if(ptr) {//VLR순회
		printf(" [%d] ", ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr)
{
	if(ptr) {//LRV순회
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf(" [%d] ", ptr->key);
	}
}


int insert(Node* head, int key)//key값을 가지는 노드 삽입
{
	Node* newNode = (Node*)malloc(sizeof(Node));//key값을 가지는 node newNode생성
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {//headNode만 존재할 때
		head->left = newNode;
		return 1;
	}

	Node* ptr = head->left;//노드형 포인터 변수 ptr 생성하고 head->left값으로 초기화

	Node* parentNode = NULL;//노드형 포인터 변수 parentNode생성하고 NULL로 초기화
	while(ptr != NULL) {//리프 노드에 갈 때까지 반복
		if(ptr->key == key) return 1;//이미 key값과 일치하는 노드가 존재할 경우 종료
		parentNode = ptr;//parentNode에 현재 ptr 값 저장
		if(ptr->key < key)//ptr의 key값이 현재 노드의 key값보다 작을 경우 왼쪽 자식 노드로 이동
			ptr = ptr->right;
		else
			ptr = ptr->left;//ptr의 key값이 현재 노드의 key값보다 클 경우 오른쪽 자식 노드로 이동
	}

	if(parentNode->key > key)//key값이 부모 노드의 key값보다 작을 경우
		parentNode->left = newNode;//부모 노드의 왼쪽 자식 노드로 nenwNode넣기
	else
		parentNode->right = newNode;//이외의 경우에는 부모 노드의 오른쪽 자식 노드로 newNode넣기
	return 1;
}


int deleteLeafNode(Node* head, int key)//tree 에 key값을 가지는 노드 삭제
{
	if (head == NULL) {//tree가 비어있을 경우
		printf("\n Nothing to delete!!\n");
		return -1;
	}

	if (head->left == NULL) {//tree가 비어있을 경우
		printf("\n Nothing to delete!!\n");
		return -1;
	}
	Node* ptr = head->left;//tree가 비어있지 않을 경우 tree에서 key값을 가지는 노드를 삭제할 때 쓸 Node형 포인터 변수 ptr head->left로 초기화

	Node* parentNode = head;//tree에서 key값을 가지는 노드를 삭제할 때 쓸 Node형 포인터 변수 parentNode head로 초기화

	while(ptr != NULL) {//tree의 끝까지 반복
		if(ptr->key == key) {//현재 ptr이 위치한 노드의 key값과 찾는 key값이 같을 경우
			if(ptr->left == NULL && ptr->right == NULL) {//ptr이 가리키는 노드가 leaf노드일 경우
				if(parentNode == head)//부모 노드가 root일 경우
					head->left = NULL;//root노드의 왼쪽 자식 노드 없애기
				if(parentNode->left == ptr)//부모 노드의 왼쪽 노드가 ptr일 겨
					parentNode->left = NULL;//왼쪽노드 비우기
				else//부모 노드의 오른쪽 노드가 ptr일 경우
					parentNode->right = NULL;//오른쪽 노드 비우기

				free(ptr);//ptr동적할당 해제시키기
			}
			else {
				printf("the node [%d] is not a leaf \n", ptr->key);//리프 노드가 아니라고 출력
			}
			return 1;
		}

		parentNode = ptr;//parentNode값에 ptr이 가리키는 현재 노드 주소값 넣기

		if(ptr->key < key)//찾고있는 key값이 현재 ptr이 가리키는 노드의 key값보다 클 경우
			ptr = ptr->right;//현재 ptr이 가리키는 노드의 오른쪽 자식 노드로 이동하기
		else//현재 ptr이 가리키는 노드의 key값보다 찾고 있는 key값이 작을 경우
			ptr = ptr->left;//현재 ptr이 가리키는 노드의 왼쪽 자식 노드로 이동하기


	}

	printf("Cannot find the node for key [%d]\n ", key);//key값과 일치하는 노드를 찾지 못했을 경우 찾지 못했다는 문자열 출력

	return 1;
}


Node* searchRecursive(Node* ptr, int key)//key값을 가지는 노드 tree에서 찾기
{
	if(ptr == NULL)
		return NULL;

	if(ptr->key < key)
		ptr = searchRecursive(ptr->right, key);
	else if(ptr->key > key)
		ptr = searchRecursive(ptr->left, key);

	return ptr;

}


Node* searchIterative(Node* head, int key)//key값을 가지는 노드 위치 출력
{
	Node* ptr = head->left;//key값을 가지는 노드 위치 저장할 노드형 포인터 변수 p head->left로 초기화

	while(ptr != NULL)//tree의 끝까지 탐색하기
	{
		if(ptr->key == key)//현재 ptr이 위치한 노드의 key값과 찾는 key값이 같을 경우 ptr위치 return
			return ptr;

		if(ptr->key < key) ptr = ptr->right;//현재 ptr이 위치한 노드의 key값보다 찾는 key값이 클 경우 현재 노드의 오른쪽 자식 노드로 이동
		else
			ptr = ptr->left;//현재 ptr이 위치한 노드의 key값보다 찾는 key값이 작을 경우 현재 노드의 왼쪽 자식 노드로 이동
	}

	return NULL;//key값과 일치하는 노드를 찾지 못하면 NULL로 return
}

void freeNode(Node* ptr)//ptr과 그 자식 노드들 다 free시키기
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head)
{
	if(head->left == head)//tree가 비어있을 경우
	{
		free(head);
		return 1;
	}

	Node* p = head->left;//tree가 비어있지 않을 경우 차례대로 노드들을 free시킬 때 쓸 Node형 포인터 변수 p 선언하고 head->left로 초기화

	freeNode(p);

	free(head);
	return 1;
}




