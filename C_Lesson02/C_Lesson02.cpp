#include <stdio.h>

int main()
{
	// 데이터의 출력
	int num = 15;
	char ch = 'a';
	double g = 42.195;

	printf("num = %d\n", num);
	printf("ch = %hhd\n", ch);
	printf("ch = %c\n", ch);
	printf("g = %f\n", g);
	printf("g = %e\n", g);	// 실수를 지수형으로 표현
	printf("15를 16진수로 표현: %x\n", num);
	printf("16을 16진수로 표현: %x\n", 16);	
	printf("부호없는 정수의 표현: %u\n", 16);	// 양의 정수
	printf("안녕하세요, 내 이름은 %s입니다\n", "홍길동");

	/*
	형식 문자
	%d : 부호가 있는 정수형 데이터
	%c : 정수형 데이터를 문자로 표현
	%f : 실수형 데이터를 소수점형태로 표현
	%e : 실수형 데이터를 지수형으로 표현
	%x(X) : 데이터를 16진수로 표현
	%u : unsigned, 양수를 출력할때 사용
	%o : 8진수
	%s : 문자열 데이터
	*/
	/*
	형식 문자의 응용

	
	*/
	// 리터럴(Literal)
	// money라는 long형 변수를 선언하고 데이터 10000을 대입하라
	long money = 10000L;
	printf("num = %d\n", num);
	float weight = 75.5F;
	
	// 정수의 부호가 없는 타입
	unsigned short age = 10000;	// 0 ~ 65535
	unsigned char sz;
	unsigned int score;
	unsigned long year;
	unsigned long long lsize = sizeof(long long);

	printf("age = %hu\n", age);
	printf("lsize = %llu\n", age);

	printf("%d\t%d\t%d\n", 1, 100, 10000);

	printf("age:%7d\n", 10);
	printf("year:%6d\n", 2010);

	printf("마라톤 거리: %6.3f\n", g);	// 6자리확보후 소수점 이하를 3자리로 제한
	printf("마라톤 거리: %.3f\n", g);	// 소수점 이하를 3자리로 제한

	return 0;
}