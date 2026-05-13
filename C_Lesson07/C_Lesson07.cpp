#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 조건문: if..else 문

/*
if (조건식) 
{
    조건식이 참일때 실행될 명령문(들)...
}
*/

/*
if (조건식)
{
    조건식이 참일때 실행될 명령문(들)...
}
else
{
    조건식이 거짓일때 실행될 명령문(들)...
}
*/

/*
if (조건식1)
{
    조건식1이 참일때 실행될 명령문(들)...
}
else if (조건식2)
{
    조건식2이 참일때 실행될 명령문(들)...
}
...
else
{
    조건식이 거짓일때 실행될 명령문(들)...
}
*/


int main()
{
    //printf("정수를 입력하세요 >>> ");
    //int num;
    //scanf("%d", &num);
    //if (num % 2 == 0)
    //{
    //    printf("num은 짝수이다.\n");        
    //}
    //else
    //{
    //    printf("num은 홀수이다.\n");
    //}

    /*
    점수를 입력받아서
    90 ~ 100: A학점
    80 ~ 89: B학점
    70 ~ 79: C학점
    60 ~ 69: D학점
     ~ 59  : F학점
    */
    printf("점수를 입력하세요 >>> ");
    int score;
    scanf("%d", &score);
    if (score >= 90)
        printf("A학점\n");
    else if (score >= 80 && score < 90)
        printf("B학점\n");
    else if (score >= 70 && score < 80)
        printf("C학점\n");
    else if (score >= 60 && score < 70)
        printf("D학점\n");
    else
        printf("F학점\n");

    printf("프로그램 종료\n");

    return 0;
}
