#include <stdio.h>	// standard input output
#include <string.h>	// 문자열(String)을 처리하는 함수들이 정의되어 있는 헤더파일

// 배열과 문자열

// 정수와 실수
// ASCII: 정수와 문자를 1:1로 매핑해놓은 가장 기본적인 코드 테이블

int main()
{
	//char ch = 97;

	// char arr[] = {97, 98, 99, 100, 101, 102};
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0' };
	// char sz[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };
	char sz[] = "Hello World";	// 11글자
	// 배열의 길이는 문자열의 길이 + 1, 문자열의 길이는 배열의 길이 - 1
	// 문자열을 완성하기위해 가장 마지막에 붙는 0('\0')을 null terminated character라고 한다.


	int len = sizeof(arr) / sizeof(char);	// 배열의 길이
	for (int i = 0; i < len; i++)
	{
		printf("%hhd", arr[i]);	// 배열의 각 아이템들의 값을 정수형으로 표현
	}
	printf("\n");	// Enter키 친 것과 같은 효과
	for (int i = 0; i < len; i++)
	{
		printf("%c", arr[i]);	// 배열의 각 아이템들의 값을 문자(ASCII코드)값으로 표현
	}
	printf("\n");
	printf("%s\n", arr);
	printf("%s\n", sz);

	len = sizeof(sz) / sizeof(char);
	printf("배열 sz의 길이: %d\n", len);
	for (int i = 0; i < len; i++)
	{
		printf("%hhd(%c)", sz[i], sz[i]);
	}
	printf("\n");

	char sz2[] = {'A', 'B', 'C', '\0', 'D', 'E', 'F'};
	printf("%s\n", sz2);

	char sz3[] = "Hell\0o World";
	printf("%s\n", sz3);

	// 문자열의 길이를 구하는 함수
	size_t length = strlen(arr);
	len = sizeof(arr) / sizeof(char);
	printf("arr 배열의 길이: %d\n", len);
	printf("arr 문자열의 길이: %llu\n", length);

	length = strlen(sz);
	len = sizeof(sz) / sizeof(char);
	printf("sz 배열의 길이: %d\n", len);
	printf("sz 문자열의 길이: %llu\n", length);

	length = strlen(sz2);
	len = sizeof(sz2) / sizeof(char);
	printf("sz2 배열의 길이: %d\n", len);
	printf("sz2 문자열의 길이: %llu\n", length);

	length = strlen(sz3);
	len = sizeof(sz3) / sizeof(char);
	printf("sz3 배열의 길이: %d\n", len);
	printf("sz3 문자열의 길이: %llu\n", length);

	return 0;
}
