#include <stdio.h>
#include <stdlib.h>

void main(){
    int list[5];//int형 배열 선언
    int *plist[5];//int형 포인터 배열 선언

    list[0] = 10;//list[0]값 지정
    list[1] = 11;//list[1]값 지정

    plist[0] = (int *)malloc(sizeof(int));//int향 포인터 동적할당
    
    printf("[----- 윤혜준 2022041021 ----- ]\n");
    
    printf("list[0] \t= %d\n", list[0]);//list[0]값 출력
    printf("list \t\t= %p\n", list);//list[0]주소값 출력
    printf("&list[0] \t= %p\n", &list[0]);//list[0]주소값 출력
    printf("list + 0 \t= %p\n", list+0);//list[0]주소값 출력
    printf("list + 1 \t= %p\n", list+1);//list[1]주소값 출력
    printf("list + 2 \t= %p\n", list+2);//list[2]주소값 출력
    printf("list + 3 \t= %p\n", list+3);//list[3]주소값 출력
    printf("list + 4 \t= %p\n", list+4);//list[4]주소값 출력
    printf("&list[4] \t= %p\n", &list[4]);//list[4]주소값 출력

    free(plist[0]);//할당 해제
}