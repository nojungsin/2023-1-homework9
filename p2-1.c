#include <stdio.h>

#define MAX_SIZE 100//MAX_SIZE 100으로 정의

float sum1(float list[], int);//sum1함수 정의
float sum2(float *list, int);//sum2함수 정의
float sum3(int n, float *list);//sum3함수 정의

float input[MAX_SIZE], answer;//float형 배열 input, 변수 answer 선언
int i;
void main(void){
    for (i=0; i < MAX_SIZE; i++)//MAX_SIZE만큼 반복하면서 input[i]에 i값 넣기
        input[i] = i;
    
    printf("[----- 윤혜준 2022041021 ----- ]\n");

    printf("--------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------\n");
    printf("input \t= %p\n", input);//input[0]주소값 출력

    answer = sum1(input, MAX_SIZE);//answer에 sum1(input, MAX_SIZE)값 넣기
    printf("The sum is : %f\n\n", answer);//answer값 출력

    printf("--------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------\n");
    printf("input \t= %p\n", input);//input[0]주소값 출력

    answer = sum2(input, MAX_SIZE);//answer에 sum1(input, MAX_SIZE)값 넣기
    printf("The sum is : %f\n\n", answer);//answer값 출력

    printf("--------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------\n");
    printf("input \t= %p\n", input);//input[0]주소값 출력

    answer = sum3(MAX_SIZE, input);//answer에 sum3(input, MAX_SIZE)값 넣기
    printf("The sum is : %f\n\n", answer);//answer값 출력

}

float sum1(float list[], int n){
    printf("list \t= %p\n", list);//list[0]주소값 출력
    printf("&list \t= %p\n\n", &list);//list주소값 출력

    int i;//int형 변수 i
    float tempsum = 0;//float형 변수 tempsum
    for (i=0; i<n; i++)
      tempsum += list[i];
    return tempsum;
}//변수로 list배열이랑 n변수 받기. n만큼 반복하면서 list[i]값들을 다 더해서 나온 값은 tempsum에 저장해 tempsum값 return

float sum2(float *list, int n){
    printf("list \t= %p\n", list);//list[0]주소값 출력
    printf("&list \t= %p\n\n", &list);//list주소값 출력

    int i;//int형 변수 i
    float tempsum = 0;//float형 변수 tempsum
    for (i=0; i<n; i++)
      tempsum += *(list+i);
    return tempsum;
}//변수로 list포인터랑 n변수 받고, n만큼 반복하면서 list가준으로 한 칸씩 옮겨가면서 나온 값들을 다 더해서 나온 값은 tempsum에 저장해 tempsum값 return

float sum3(int n, float *list){
    printf("list \t= %p\n", list);//list[0]주소값 출력
    printf("&list \t= %p\n\n", &list);//list주소값 출력

    int i;//int형 변수 i
    float tempsum = 0;//float형 변수 tempsum
    for (i=0; i<n; i++)
      tempsum += *(list+i);
    return tempsum;
}//변수로 n변수랑 list포인터 받고, n만큼 반복하면서 list기준으로 한 칸씩 옮겨가면서 나온 값들을 다 더해서 나온 값은 tempsum에 저장해 tempsum값 return