#include <stdio.h>

struct student {
    char lastName[13];//char형 크기 13인 배열 lastName
    int studentId;//int형 변수 studentId
    short grade;//short형 변수 grade
};

int main(){
    struct student pst;//student구조체 변수 pst선언

    printf("[----- 윤혜준 2022041021 ----- ]\n");

    printf("size of student = %ld\n", sizeof(struct student));//struct student 크기 출력
    printf("size of int = %ld\n", sizeof(int));//int크기 출력
    printf("size of short = %ld\n", sizeof(short));//short크기 출력

    return 0;
}