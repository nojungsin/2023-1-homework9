#include <stdio.h>

struct student1 {
    char lastName;//char형 변수 lastName
    int studentId;//int형 변수 studentId
    char grade;//char형 변수 grade

};//구조체 이름 student1

typedef struct {
    char lastName;//char형 변수 lastName
    int studentId;//int형 변수 studentId
    char grade;//char형 변수 grade
} student2;//구조체 이름 student2

int main(){
    struct student1 st1 = {'A', 100, 'A'};//student1구조체 변수 st1의 변수 lastName, studentId, grade에 차례대로 A, 100, A를 넣는다

    printf("[----- 윤혜준 2022041021 ----- ]\n");

    printf("st1.lastName = %c\n", st1.lastName);//st1.lastName 값 A 출력
    printf("st1.studentId = %d\n", st1.studentId);//st1.studentId값 100 출력
    printf("st1.grade = %c\n", st1.grade);//st1.grade값 A출력

    student2 st2 = {'B', 200, 'B'};//student2구조체 변수 st2의 변수 lastName, studentId, grade에 차례대로 B, 200, B를 넣는다


    printf("\nst2.lastName = %c\n", st2.lastName);//st2.lastName값 B 출력
    printf("st2.studentId = %d\n", st2.studentId);//st2.studentId값 200 출력
    printf("st2,grade = %c\n", st2.grade);//st2.grade값 B 출력

    student2 st3;//student2구조체 변수 st3
    st3 = st2;//st3에 st2값 넣기

    printf("\nst3.lastName = %c\n", st3.lastName);//st3.lastName값 B 출력
    printf("st3.studentId = %d\n", st3.studentId);//st3.studentId값 200출력
    printf("st3.grade = %c\n", st3.grade);//st3.grade값 B출력

    if ((st3.lastName == st2.lastName)&&(st3.grade == st2.grade)&&(st3.studentId == st2.studentId))//st3과 st2와 완전히 일치하는 지 확인하게 각각의 변수들이 일치하는지 확인
       printf("equal\n");
    else printf("not equal\n");

    return 0;
}