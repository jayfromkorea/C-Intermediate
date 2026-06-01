#include "emp.h"
#include "error.h"

void show_menu() 
{
	// system(): console 명령어를 실행시켜 주는 함수
	system("cls");	// Console 화면 clear

	printf("===== 사원 관리(ver .0)=====\n");
	printf("========================\n\n");

	printf("a. 사원정보 입력\n");
	printf("b. 사원정보 조회\n");
	printf("c. 사원정보 수정\n");
	printf("d. 사원정보 삭제\n");
	printf("========================\n\n");

	printf("e. 부서 입력\n");
	printf("f. 부서 조회\n");
	printf("g. 부서 수정\n");
	printf("h. 부서 삭제\n");
	printf("========================\n\n");

	printf("i. 직급 입력\n");
	printf("j. 직급 조회\n");
	printf("k. 직급 수정\n");
	printf("l. 직급 삭제\n");
	printf("========================\n\n");

	printf("x. 프로그램 종료\n");
}

int select_menu()
{
	printf("\n\n");
	printf("메뉴를 선택 입력하세요 >>> ");

	// _getch(): 문자 하나를 입력하면 즉시 입력된 값을 반환하는 함수
	int menu = _getch();

	return menu;
}

int employee_procedure() {
	
	// 각 정보들을 저장하는 배열
	EMPLOYEE* pEmp = NULL;
	size_t emp_count = 0;

	PART* pPart = NULL;
	size_t part_count = 0;

	RANK* pRank = NULL;
	size_t rank_count = 0;

	// 저장된 파일로부 배열데이터 로드하기

	int menu = 0;

	do
	{
		// 메뉴 출력
		show_menu();

		// 메뉴 선택
		menu = select_menu();
		// 선택된 메뉴에 따른 기능 수행
		switch (menu)
		{
			case 'a':
			case 'b':
			case 'c':
			case 'd':break;

			case 'e':
				part_count = input_part(&pPart, part_count); 
				break;
			case 'f': print_part(pPart, part_count);
				break;
			case 'g':
			case 'h': break;

			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'x':
			default: error_message(WRONG_MENU_SELECTED);
		}

		// 메뉴 출력으로 이동

	} while (menu != 'x'); // 메뉴 선택에 따라 탈출 여부가 결정됨

	return 0;
}

// 나중에 inser 기능도 구현!!!!!!!
size_t input_part(PART** ppNewPart, size_t count) 
{
	if (!ppNewPart)
	{
		//error message
		return 0;
	}

	// 기존 배열의 주소를 저장
	PART* pOldPart = *ppNewPart;

	system("cls");

	PART part = { 0 };	// 입력을 처리할 임시 변수
	printf("사원번호를 입력하세요 >>> ");
	scanf("%hu", &part.id);

	char tmp; scanf("%c", &tmp); // 입력낭비버퍼 청소하기

	printf("사원 이름을 입력하세요 >>> ");
	fgets(part.name, MAX_NAME-1, stdin);
	int len = strlen(part.name);
	part.name[len - 1] = '\n'; // \n을 \0으로 바꿔서 줄바꿈이 발생하는 상황을 제거

	PART* pNewPart = NULL;
	size_t new_count = count + 1;
	size_t new_size = sizeof(PART) * new_count;

	
	pNewPart = (PART*)malloc(new_size);
	if (!pNewPart) {
		// 기존 배열 크기를 반환하고 종료
		return count;
	}



	// 기존의 배열이 존재한다면...
	if (pOldPart) //  질문!!!!!!!!!
	{
		// 새 배열에 기존의 배열을 그대로 복사한다.
		// 마지막에 한칸이 남음, 그건 새로 입력된 part에 할당된다

		// memcpy(dest, src, size)는 메모리 블럭을 src에서 dest로 size만큼 복사한다.
		memcpy(pNewPart, pOldPart, sizeof(PART) * count);
		free(pOldPart); // 기존 배열은 해제한다
	}

	memcpy(pNewPart + count, &part, sizeof(PART));

	// 기존 배열의 주소를 업데이트 한다.
	*ppNewPart = pNewPart;

	return new_count;
}

void print_part(PART* pPart, size_t count)
{
	system("cls");
	for (size_t i = 0; i < count; i++) {
		printf("%d\t%s\n", pPart[i].id, pPart[i].name);
	}

	printf("계속하려면 아무키나 누르세요...\n");
	_getch();
}