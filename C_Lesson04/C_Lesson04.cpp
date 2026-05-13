// 상수(Constant)

#include <stdio.h>

// 매크로 상수
#define MARATHONE       42.195F
#define CHECK_PARAM(x)  if(!x) return

int main()
{
    int num;    // 정수형 변수
    float f;    // 실수형 변수

    num = 5;    // 5,10 ===> 리터럴(Literal)
    f = 3.14F;

    // 상수(Constant): 더이상 변경할 수 없는 고정변수(값)
    const float pi = 3.14F;
    const int MAX_NUMBER = 50;

    num = 10;
    // pi = 3.141592F;
    f = MARATHONE;

    return 0;
}
