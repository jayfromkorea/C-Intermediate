#include <stdio.h>

// 형변환(Type casting)

int main()
{
    int num = 5;    // num은 정수형 변수, sizeof() --> 4byte
    double f;   // 실수형 변수, sizeof() ---> 8byte

    f = num;    // 묵시적 형변환 발생
    printf("f = %f\n", f);

    num = f;    // 묵시적 형변환 발생
    printf("num = %d\n", num);

    f += 0.9;   // 5.1
    printf("f = %f\n", f);

    num = f;    // 묵시적 형변환, 소수점이하는 버림
    printf("num = %d\n", num);

    // 명시적 형변환: (데이터타입)x, x가 앞에 주어진 데이터 타입으로 변환됨
    num = (int)(f * 2.0);

    f = (double)5;

    //
    num = 10;
    int div = 3;
    
    f = (double)num / div;  // (double)(num / div) ==> 3.0000
    printf("f = %f\n", f);

    // overflow: 해결방법 없음
    char a;
    num += 500; // num = 510
    a = (char)num;

    return 0;
}
