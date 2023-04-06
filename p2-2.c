#include <stdio.h>

void print_one(int *ptr, int rows);//print_onc함수 선언

int main(){
    int one[] = {0, 1, 2, 3, 4};//int형 배열에 차례대로 0, 1, 2, 3, 4값 저장

    printf("[----- 윤혜준 2022041021 ----- ]\n");

    printf("one = %p\n", one);//one[0]주소값 출력
    printf("&one = %p\n", &one);//one주소값 출력
    printf("&one[0] = %p\n", &one[0]);//one[0]주소값 출력
    printf("\n");

    printf("--------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("--------------------\n");
    print_one(&one[0], 5);

    printf("--------------------\n");
    printf(" print_one(one, 5) \n");
    printf("--------------------\n");
    print_one(one, 5);

    return 0;

}

void print_one(int *ptr, int rows){
    int i;
    printf("Address \t Contents\n");
    for (i=0; i< rows; i++)
       printf("%p \t %5d\n", ptr + i, *(ptr+i));//입력받은 함수 ptr에 차례대로 i만큼 더한 곳의 주소값과 그 곳에 저장된 값 출력
    printf("\n");
}