#include <stdio.h>

int main()
{
    // 변수와 데이터 타입
    // 
    // 변수의 선언 방법
    // 데이터타입 변수명;

    // ASCII code ---> UNICODE

    // 숫자 ---> 정수(Integer), 실수(Real, Float, Double)

    // 32GB

    // 비트(bit): 0, 1 == 8개(8bit) == 1Byte

    // 1byte는 데이터를 처리하는 가장 작은 단위
    // 1byte * 1024byte ==> 1Kbyte ===> 1Mbyte ===> 1Gb

    // Windows 64비트 운영체제
    // 정수형(Integer): 
    // char: 1 byte
    // short: 2 byte
    // int: 4 byte
    // long: 4 byte(8 byte)
    // long long: 8 byte

    // 실수형:
    // float: 4byte
    // double: 8byte
    // long double: ???

    // 변수의 선언
    char ch;        // -128 ~ 0 ~ 127
    short num;      // -2^16 ~ 0 ~ 2^16-1, -32,768 ~ 32,767
    int kor;        // -2^32 ~ 0 ~ 2^32-1, 
    long money;
    long long big;

    float f;
    double g;
    long double gh;

    // sizeof([변수 또는 자료형]): 주어진 식별자의 메모리 할당 크기를 알려준다.

    printf("char형 변수의 크기: %d bytes\n", sizeof(ch));
    printf("short형 변수의 크기: %d bytes\n", sizeof(short));
    printf("int형 변수의 크기: %d bytes\n", sizeof(int));
    printf("long형 변수의 크기: %d bytes\n", sizeof(long));
    printf("long long형 변수의 크기: %d bytes\n", sizeof(long long));

    printf("float형 변수의 크기: %d bytes\n", sizeof(f));
    printf("double형 변수의 크기: %d bytes\n", sizeof(g));
    printf("long double형 변수의 크기: %d bytes\n", sizeof(long double));

    // 1byte --> 8bit
    // 1bit는 0 또는 1의 서로 다른 두개의 데이터를 표현(저장)할 수 있다.
    // 2^8 ===> 256가지의 서로 다른 데이터를 표현할 수 있다.
    
    ch = 127;
    printf("ch = %d\n", ch);

    f = 3.14F;  // 0.314E+1
    printf("f = %f\n", f);

    ch = 65;    // 0100 0001
    printf("ch = %c\n", ch);

    /*
    8421
    ---------
    0000 : 0
    0001 : 1
    0010 : 2
    0011 : 3
    0100 : 4
    0101 : 5
    0110 : 6
    0111 : 7
    1000 : 8
    ...
    1111 : 15
    0001 0000
    0111 1111 ---> 1111 1111? -127    
    
    64 + 32 + 16 + 8 + 4 + 2 + 1
    2의 보수를 취하는 방법으로 음수를 표현한다.
    */

    // 실수형 데이터의 표현(처리): 가수부 + 지수부

    return 0;
}
