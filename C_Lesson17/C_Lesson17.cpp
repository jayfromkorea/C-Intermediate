#include <stdio.h>

// Pointer: 메모리의 주소를 저장하는 변수

// 정수: char(1), short(2), int(4), long(4), long long(8) (이것들은 모두 unsigned를 사용할 수 있음)
// 실수: float(4), double(8), long double(8)
// 주소: char*, ... long double*

int main()
{
    int num;    // 4byte
    float pi;   // 4byte

    num = 100;
    pi = 3.14F;  // F를 안 하면 묵시적 형변환이 일어남

    printf("num의 값: %d\tnum의 크기: %llubytes\n", num, sizeof(num));
    printf("pi의 값: %.2f\tnum의 크기: %llubytes\n", pi, sizeof(pi));

    // 주소 연산자: &
    printf("num의 주소: %p\n", &num);
    printf("pi의 주소: %p\n", &pi);

    // 주소값은 Windows 64bit 시스템에서 8byte로 표현된다
    int* p1 = &num;
    float* p2 = &pi;

    printf("p1의 값: %p\n", p1);
    printf("p2의 값: %p\n", p2);

    // 포인터 변수는 어떠한 경우에도 주소만 저장할 수 있다
    // 모든 포인터 변수들의 크기는 64bit System에서 8byte의 크기를 갖는다
    printf("p1의 크기: %llubytes\n", sizeof(p1));
    printf("p2의 크기: %llubytes\n", sizeof(p2));

    printf("p1이 가리키고 있느 곳의 값: %d\n", *p1);
    printf("p2이 가리키고 있느 곳의 값: %.2f\n", *p2);

    // num의 값 변경하기
    num = 200;
    printf("p1이 가리키고 있느 곳의 값: %d\n", *p1);

    // p2가 가리키고 있는 값을 변경
    *p2 = 42.195F;
    printf("pi의 값: %.3f\n", pi);

    // 포인터 활용의 장점
    // 1. App에서 메모리 사용의 크기를 절약할 수 있다
    // 2. 처리 속도가 빨라진다.
    

    // 배열과 포인터
    int arr[] = { 10, 20, 30, 40, 50 };
    printf("arr배열의 크기: %llubytes\n", sizeof(arr));
    // 배열명: 해당 배열의 시작 주소
    int* p3 = arr;
    printf("arr의 주소: %p\n", arr);
    printf("p3의 값: %p\n", p3);

    return 0;
}