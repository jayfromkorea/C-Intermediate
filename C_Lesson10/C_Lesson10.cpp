
#include <stdio.h>
// for 반복문

/*
for(초기식; 조건식; 증감식) --> for(;;)

초기식: 반복문을 실행할때 딱 한번만 실행할 명령문, 변수들 초기화
조건식: 반복 조건을 체크하는 조건식, 참이면 계속 반복됨, 거짓이면 종료됨
증감식: 매 반복할때마다 가장 마지막에 실행되는 명령문, 보통 컨트롤 변수의 증감 처리를 함
*/

int main()
{
	//int i = 0;	// 정수형 변수 선언 및 0으로 초기화
	//while (i < 10)
	//	printf("i = %d\n", i++);
	for (int i = 0; i < 10; i++)
		printf("i = %d\n", i);
	
	//for (;;)	// for 무한 반복문
	//{
	//	printf("1");
	//}	
	int tot = 0;
	for (int i = 0; i <= 10; i++)
	{
		// 여기에서 i는 for문 지역안에서만 사용 가능한 지역변수이다.
		tot += i;
	}
	printf("total = %d\n", tot);	

	// 구구단 2단
	for (int i = 1; i < 10; i++)
	{
		printf("2 x %d = %d\n", i, 2 * i);
	}

	// 
	for (int i = 2; i <= 10; i += 2)
		printf("i = %d\n", i);

	//for (int i = 0; ; i++)	// 조건문이 없으므로 무한반복
	//{
	//	printf("i = %d\n", i);
	//}

	// for반복문은 일반적으로 반복횟수가 명확하게 지정되어 있을때 사용한다.
	for (int i = 0; i < 5; i++)	// 
	{
		printf("*");
	}	

	printf("프로그램이 종료됨!!!\n");

    return 0;
}
