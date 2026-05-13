#include <stdio.h>

// 함수의 원형 정의(함수의 선언)
int sum(int);
int add(int, int);

// 1부터 n까지의 모든 정수들의 합을 구하는 함수를 정의하세요
int main()
{
    // Declare
    int total;  // 변수의 정의(변수의 선언)
    total = sum(10);
    printf("10까지의 합: %d\n", total);
    printf("3 + 5 = %d\n", add(3, 5));

    return 0;
}


// 함수의 정의는 호출보다 항상 먼저 정의되어 있어야 한다!
int sum(int n)  
{
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += i;
    }

    return tot;
}

int add(int num1, int num2)
{
    return num1 + num2;
}
