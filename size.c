#include <stdio.h>
#include <stdlib.h>

void main(){

    int **x;//int형 더블포인터 변수 x

    printf("[----- 윤혜준 2022041021 ----- ]\n");

    printf("sizeof(x) = %lu\n", sizeof(x));//x크기 출력
    printf("sizeof(*x) = %lu\n", sizeof(*x));//*x크기 출력
    printf("sizeof(**X) = %lu\n", sizeof(**x));//**x크기 출력
}