#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	// printf, scanf, fgets, sprintf
// #include <string.h>	// strlen, strcpy, strcmp, strstr ...

// 함수(Function)
// 
// 함수의 정의(Define a function)
// 함수의 처리결과는 무조건 한개다!!!
// [함수가 처리한 결과의 데이터 타입] [함수의 이름]( [함수의 입력값 들...] )
//                                         '+', '-', '*', '/' 
// [함수의 반환형] [함수의 이름]([매개변수 들...])
double operation(double num1, double num2, char op)
{
	// 함수가 반환할 결과를 저장하는 변수
	double result;

	switch (op)
	{
	case '+':
		result = num1 + num2;
		break;	// switch문을 빠져나가는 break

	case '-':
		result = num1 - num2;
		break;	// switch문을 빠져나가는 break

	case '*':
		result = num1 * num2;
		break;	// switch문을 빠져나가는 break

	case '/':
		// num2가 0이면 result에 0을 아니면 num1 / num2를 대입
		result = (num2 == 0) ? 0 : num1 / num2;
		break;	// switch문을 빠져나가는 break

	default:
		result = 0;		
	}

	// return : 처리한 결과를 호출한쪽에 반환한다, 즉시 해당 함수를 종료시킴
	return result;
}

// 함수의 목적으로 구분: 생산형, 소비형

// 소비형 함수: 반환값이 없는 함수
// 매개변수 : Parameters, Arguments, 인수, 인자
// void: 반환값 없음
void show_my_age(int age)
{
	// age에 음수가 들어오면 출력하면 안됨: business rule
	if (age < 0)
		return;	// void함수에서 return은 함수의 즉시 종료 기능이다.

	printf("제 나이는 %d살 입니다.", age);
}

// 사용자로부터 실수값을 입력받아서 반환하는 함수
double input_double_value()
{
	double result;

	printf("실수형으로 값을 입력해주세요 >>> ");
	scanf("%lf", &result);	// double형으로 입력받기는 %lf

	return result;
}

// 사용자로부터 +, -, *, / 중 한개를 입력받아서 반환하는 함수
char input_operator()
{
	char op;
	do
	{
		scanf("%c", &op);	// 입력버퍼를 낭비시킴(엔터키 없앰)

		printf("연산자(+,-,*,/)를 입력하세요 >>> ");
		scanf("%c", &op);
	} while (op != '+' && op != '-' && op != '*' && op != '/');
	
	return op;
}


// c언어로 만든 프로그램(app)은 main함수에서 시작해서 main함수에서 끝난다.
// 간단한 계산기 app
int main()
{	
	// 숫자 두개를 입력받고 연산자를 입력받아서 계산을 하는 함수를 정의
	double a = input_double_value();
	double b = input_double_value();
	char op = input_operator();
	
	// 함수의 호출(Call a function)
	// 함수의 이름과 매개변수의 개수와 순서가 정확하게 일치해야 한다.
	double result = operation(a, b, op);
	printf("%.3f %c %.3f = %.3f\n", a, op, b, result);
	
	//// a와 b를 더한 결과에서 다시 b를 곱하여 출력하기
	//printf("%.3f\n", operation(result, b, '*'));
	//show_my_age(10);	// 호출하고 반환값을 돌려받을 수 없음

	// main함수를 종료시키면서 exit 코드를 반환한다.
	return 0;	// exit code가 0이면 정상적인 종료를 의미함
}
