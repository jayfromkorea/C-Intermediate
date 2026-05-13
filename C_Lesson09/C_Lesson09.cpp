#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 반복문: while, do~while, for
/*
while(조건식)
{
	조건식이 참(true)인동안 반복실행할 명령문(들)
}

1. 조건식이 처음부터 거짓이면 반복루프를 진입하지 않을 수도 있다.
2. 반복횟수가 명확하게 지정되어 있지 않은 경우에 주로 사용한다.
*/

/*
지역(Local)
{
	int a;	// 지역변수: 지역안에서 같은 이름으로 하나만 선언 가능
}

*/

int main()
{
	int i = 0;	// 정수형 변수 선언 및 0으로 초기화
	while (i < 10)
		printf("i = %d\n", i++);	// 		
	

	printf("while문이 종료되었음\n");
	printf("i = %d\n", i);
	
	// 1 ~ 10까지의 합구하기
	i = 1;
	int tot = 0;
	while (i <= 10)		//0 + 1 + 2 + 3 + 4 + 5 + ... + 9 + 10 = 55
	{
		tot += i;	// tot = tot + i;
		i++;
	}
	printf("total = %d\n", tot);

	// 사용자로부터 정수값들을 입력받아서 그 값들을 누적시키고 출력하기
	// 단, 사용자가 음수를 입력하면 누적시키지 않고 즉시 종료하고,
	// 그때까지의 누적합을 출력하세요	
	tot = 0;
	while (1)	// 무한반복문
	{
		printf("정수값을 입력하세요(음수 입력시 종료): ");
		scanf("%d", &i);	// &: 앰퍼샌드(ampersand), &변수 --> 주소 연산자
		if (i < 0)
			break;	// 현재의 while문 지역을 즉시 탈출시킴		

		tot += i;
	}
	printf("total = %d\n", tot);

	// do ~ while: 반복 루프를 적어도 1번은 실행한다!
	i = 0;
	tot = 0;
	do
	{
		tot += i;

		printf("정수값을 입력하세요(음수 입력시 종료): ");
		scanf("%d", &i);

	} while ( i >= 0 );
	printf("total = %d\n", tot);

	// 
	char menu, tmp;	// tmp: 자동입력 방지를 위한 입력버퍼 청소용 변수
	do
	{
		scanf("%c", &tmp);	// 입력버퍼 클리어

		printf("1. 새파일\n");
		printf("2. 파일열기\n");
		printf("3. 파일저장\n");
		printf("x. 종료\n");
		printf("메뉴를 선택하세요 :");
		scanf("%c", &menu);	// ascii code(문자값)로 입력받음

		switch (menu)
		{
		case '1': printf("새로운 파일을 만듭니다\n"); break;
		case '2': printf("기존의 파일을 오픈합니다\n"); break;
		case '3': printf("파일을 저장합니다\n"); break;
		case 'x': printf("프로그램을 종료합니다\n"); break;
		}		

	} while (menu != 'x');

	return 0;
}