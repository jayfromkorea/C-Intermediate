// 전처리문(pre-processing)
// 컴파일하기전에 처리되는 명령문
// include: 뒤에 나오는 파일을 현재 열린 이 파일에 포함시켜라!!!
#include <stdio.h>

/*
이것도 주석입니다.
이 영역에 여러줄 주석을 만들수 있습니다.
이 영역도 컴파일러가 해석하지 않습니다.
*/

// C언어는 하나의 main()함수를 갖는다.
// 약속되어 있는 함수이므로 절대 바꾸면 안된다.
int main() // Main(x), MAIN(x)
{
	// 주석(Comment): 인간이 메모하기위해 적는 코드
	// 주석은 컴파일러가 해석하지 않습니다.
	printf("Hello C\n");	// C언어의 가장 기본적인 출력 함수
	printf("Nice to\n meet\t you\n");
	printf("Good Bye\r");
	printf("So long\b");

	printf("\nI\'m a boy\n");
	printf("\nI\'m a \"Piano\\Man\"\n");
	printf("C:\\Users\\Documents\\C_Lesson.exe\n");


	// 제어문자 : \(역슬래시)와 붙어서 문자 한개로 명령이 구성된다.
	// 커서를 제어하는 명령 문자
	// \n : 줄바꿈(New Line)
	// \t : tab 간격 만큼 커서를 우측으로 이동시킴
	// \r : 커서를 줄바꿈없이 그 줄의 가장 첫번째 열로 이동시킴
	// \b : Backspace, 커서 바로 앞에 있는 글자 하나를 지움
	// \", \' : 출력물 내부에 인용부호(", ')를 표현하기 위해 사용
	// \a : alert, 사운드를 표시함
	// \\ : \(역슬래시)한개를 표현

	return 0;	// 함수의 종료와 호출한 쪽에 값을 반환하는 명령어
} // 중괄호 사이의 영역을 로컬(지역)이라고 부른다.