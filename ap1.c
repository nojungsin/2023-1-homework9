#include <stdio.h>
#include <stdlib.h>

void main(){
    int list[5];//int 형 배열 선언
    int *plist[5] = {NULL,};//int형 포인터 배열 선언

    plist[0] = (int *)malloc(sizeof(int));//int형 동적할당

    list[0] = 1;
    list[1] = 100;

    *plist[0] = 200;

    printf("[----- 윤혜준 2022041021 ----- ]\n");
    
    printf("list[0] = %d\n", list[0]);//list[0]값 출력
    printf("&list[0] = %p\n", &list[0]);//list[0]주소값 출력
    printf("list = %p\n", list);//list[0]주소값 출력
    printf("&list = %p\n", &list);//list[0]주소값 출력

    printf("--------------------\n");
    printf("list[1] = %d\n", list[1]);//list[1]값 출력
    printf("&list[1] = %p\n", list[1]);//list[1]주소값 출력
    printf("*(list+1) = %d\n", *(list+1));//list[1]값 출력
    printf("list+1 = %p\n", list+1);//list[1]주소값 출력
     
    printf("--------------------\n");
    printf("*plist[0] = %d\n", *plist[0]);//plist[0]값 출력
    printf("&plist[0] = %p\n", &plist[0]);//plist[0]주소값 출력
    printf("&plist = %p\n", &plist);//plist[0]주소값 출력
    printf("plist = %p\n", plist);//plist[0]주소값 출력
    printf("plist[0] = %p\n", plist[0]);//plist[0]값 출력
    printf("plist[1] = %p\n", plist[1]);//plist[0]동적할당된 곳 주소 출력
    printf("plist[2] = %p\n", plist[2]);//할당 안돼서 주소 없음
    printf("plist[3] = %p\n", plist[3]);//할당 안돼서 주소 없음
    printf("plist[4] = %p\n", plist[4]);//할당 안돼서 주소 없음

    free(plist[0]);//할당 해제
}