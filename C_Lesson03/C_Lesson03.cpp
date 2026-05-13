#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	// 사용자로부터 데이터 입력받기
	// 표준 출력 함수: printf()
	// 표준 입력 함수: scanf(), 콘솔 입력장치로부터 데이터를 입력받는 함수

	int age;
	printf("나이를 입력하세요 >>> ");
	scanf("%d", &age);	// 
	printf("입력된 나이는 %d살 입니다\n", age);

	int num1, num2;
	printf("두개의 정수를 공백을 두어 입력하세요 >>> ");
	scanf("%d %d", &num1, &num2);	// 
	printf("%d + %d = %d\n", num1, num2, num1 + num2);

	char ch;
	scanf("%c", &ch);	// 입력버퍼를 낭비시킴(입력버퍼 청소)

	printf("한개의 문자를 입력하세요 >>> ");
	scanf("%c", &ch);
	printf("입력된 데이터: %c(%x)\n", ch, ch);
	
	return 0;
}
