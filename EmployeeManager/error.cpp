#include "emp.h"
#include "error.h"


void error_message(const char* message)
{
	system("cls");
	printf(message);
	printf("\n");
	printf(PRESS_ANY_KEY);
	_getch(); // 잠깐 정지시키는 역할을 함

}