#include "emp.h"
#include "error.h"

void input(char* buffer, size_t len) //  사용자에게 입력을 받는 함수
{
	fgets(buffer, len, stdin);
	int length = strlen(buffer);
	buffer[length- 1] = '\n'; // \n을 \0으로 바꿔서 줄바꿈이 발생하는 상황을 제거
}

void show_menu() 
{
	// system(): console 명령어를 실행시켜 주는 함수
	system("cls");	// Console 화면 clear

	printf("===== EMPLOYEE 관리(ver 1.0)=====\n");
	printf("========================\n\n");

	printf("a. EMPLOYEE_TITLEINFORMATION CREATE\n");
	printf("b. EMPLOYEE_TITLEINFORMATION READ\n");
	printf("c. EMPLOYEE_TITLEINFORMATION UPDATE\n");
	printf("d. EMPLOYEE_TITLEINFORMATION DELETE\n");
	printf("========================\n\n");

	printf("e. INFORMATION CREATE\n");
	printf("f. DEPARTMENT READ\n");
	printf("g. DEPARTMENT UPDATE\n");
	printf("h. DEPARTMENT DELETE\n");
	printf("========================\n\n");

	printf("i. RANK CREATE\n");
	printf("j. RANK READ\n");
	printf("k. RANK UPDATE\n");
	printf("l. RANK DELETE\n");
	printf("========================\n\n");

	printf("x. 프로그램 종료\n");
}

int select_menu()
{
	printf("\n\n");
	printf("메뉴를 선택 CREATE하세요 >>> ");

	// _getch(): 문자 하나를 CREATE하면 즉시 CREATE된 값을 반환하는 함수
	int menu = _getch();

	return menu;
}

int employee_procedure() {
	
	// 각 INFORMATION들을 저장하는 배열
	EMPLOYEE* pEmp = NULL;
	size_t emp_count = 0;

	BASE_INFO* pPart = NULL;
	size_t part_count = 0;

	RANK* pRank = NULL;
	size_t rank_count = 0;

	// 저장된 파일로부 배열데이터 로드하기
	part_count = load_data(&pPart, PART_FILE);
	part_count = load_data(&pRank, RANK_FILE);

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

			case 'e':	// 부서 입력
				part_count = input_base(&pPart, part_count, S_PART);
				save_data(pPart, part_count, PART_FILE);	// 실시간 저장
			case 'f': // 부서 정보 출력
				print_base(pPart, part_count, S_PART);
				break;
			case 'g':	// 부서 정보 업데이트
				update_base(pPart, part_count, S_PART);
				save_data(pPart, part_count, PART_FILE);	// 실시간 저장
				print_base(pPart, part_count, S_PART);
				break;
			case 'h': // 부서 정보 삭제
				part_count = delete_base(&pPart, part_count, S_PART);
				save_data(pPart, part_count, PART_FILE);	// 실시간 저장
				print_base(pPart, part_count, S_PART);
				break;

			case 'i': // 직급 정보 입력
				rank_count = input_base(&pRank, rank_count, S_RANK);
				save_data(pRank, rank_count, RANK_FILE);	// 실시간 저장
			case 'j': // 부서 정보 출력
				print_base(pRank, rank_count, S_RANK);
				break;
			case 'k':
				// 직급 정보 업데이트
				update_base(pRank, rank_count, S_RANK);
				save_data(pRank, rank_count, PART_FILE);	// 실시간 저장
				print_base(pRank, rank_count, S_RANK);
			case 'l': // 직급 정보 삭제
				part_count = delete_base(&pRank, rank_count, S_RANK);
				save_data(pRank, rank_count, PART_FILE);	// 실시간 저장
				print_base(pRank, rank_count, S_RANK);
				break;
			case 'x': break;
			default: error_message(WRONG_MENU_SELECTED);
		}

		// 메뉴 출력으로 이동

	} while (menu != 'x'); // 메뉴 선택에 따라 탈출 여부가 결정됨

	FREE(pEmp);
	FREE(pPart);
	FREE(pRank)

	return 0;
}

// 나중에 inser 기능도 구현!!!!!!!
size_t input_base(BASE_INFO** ppData, size_t count, const char* type) 
{
	if (!ppData)
	{
		//error message
		return 0;
	}

	// 기존 배열의 주소를 저장
	BASE_INFO* pOldData = *ppData;

	BASE_INFO base = { 0 };	// 입력을 처리할 임시 변수
	

	ushort tmp_id = NULL;
	do
	{
		system("cls");

		printf("%s 코드를 입력하세요 >>> ", type);
		scanf("%hu", &tmp_id);
		
	} while (find_base_by_id(pOldData, count, tmp_id) >= 0);

	// 입력이 정상적으로 처리되었으면 part.id에 임시 id를 입력받는다
	base.id = tmp_id;

	// 입력낭비버퍼 청소하기
	getchar();

	printf("%s 이름을 입력하세요 >>> ", type);
	fgets(base.name, MAX_NAME-1, stdin);
	int len = strlen(base.name);
	base.name[len - 1] = '\0'; // \n을 \0으로 바꿔서 줄바꿈이 발생하는 상황을 제거

	BASE_INFO* pNewData = NULL;
	size_t new_count = count + 1;
	size_t new_size = sizeof(BASE_INFO) * new_count;

	
	pNewData = (BASE_INFO*)malloc(new_size);
	if (!pNewData) {
		// 기존 배열 크기를 반환하고 종료
		return count;
	}



	// 기존의 배열이 존재한다면...
	if (pOldData) //  질문!!!!!!!!!
	{
		// 새 배열에 기존의 배열을 그대로 복사한다.
		// 마지막에 한칸이 남음, 그건 새로 CREATE된 part에 할당된다

		// memcpy(dest, src, size)는 메모리 블럭을 src에서 dest로 size만큼 복사한다.
		memcpy(pNewData, pOldData, sizeof(BASE_INFO) * count);
		free(pOldData); // 기존 배열은 해제한다
	}

	memcpy(pNewData + count, &base, sizeof(BASE_INFO));

	// 기존 배열의 주소를 업데이트 한다.
	*ppData = pNewData;

	return new_count;
}

size_t input_base_insert(PART** ppNewPart, size_t count, int pos)
{
	if (!ppNewPart) return 0;

	PART* pOldPart = *ppNewPart;
	system("cls");

	PART part = { 0 };
	printf("EMPLOYEE 번호를 CREATE하세요 >>> ");
	scanf("%hu", &part.id);
	CLEAR_BUFFER;

	printf("EMPLOYEE 이름을 CREATE하세요 >>> ");
	input(part.name, MAX_NAME - 1);

	// clamp pos
	if (pos < 0) pos = 0;
	if (pos > (int)count) pos = (int)count;

	size_t new_count = count + 1;
	PART* pNewBase = (PART*)malloc(sizeof(PART) * new_count);
	if (!pNewPart) return count;

	// copy elements before pos
	if (pOldPart && pos > 0) {
		memcpy(pNewPart, pOldPart, sizeof(PART) * pos);
	}

	// insert new element
	pNewBase[pos] = part;

	// copy elements after pos (count - pos elements)
	if (pOldPart && (count - pos) > 0) {
		memcpy(pNewPart + pos + 1, pOldPart + pos, sizeof(PART) * (count - pos));
	}

	free(pOldPart);
	*ppNewPart = pNewBase;
	return new_count;
}


void update_base(BASE_INFO* pData, size_t count, const char* type)
{
	// 수정이 필요한 아이템을 선택하기 위한 목록을 보여줌
	print_base(pData, count, type, false);

	// 수정할 부서정보의 코드를 입력받음
	printf("업데이트할 %s 코드를 입력하세요 >>> ", type);
	ushort tmp_id;	
	scanf("%hu", &tmp_id);

	int index = find_base_by_id(pData, count, tmp_id);
	if (index < 0)
	{
		printf("잘못 입력했습니다.");
		return;
	}

	// 부서 코드를 새로 입력받을지 여부는 선택 사항
	// 입력낭비버퍼 청소하기
	getchar();

	printf("%s 이름을 입력하세요 >>> ", type);
	fgets(pData[index].name, MAX_NAME - 1, stdin);
	int len = strlen(pData[index].name);
	pData[index].name[len - 1] = '\0'; // \n을 \0으로 바꿔서 줄바꿈이 발생하는 상황을 제거
}

size_t delete_base(BASE_INFO** ppData, size_t count, const char* type)
{
	if (!ppData || !count) return count;

	BASE_INFO* pOldData = *ppData;

	// 삭제가 필요한 아이템을 선택하기 위한 목록을 보여줌
	print_base(pOldData, count, type, false);

	// 수정할 부서정보의 코드를 입력받음
	printf("삭제할 %s 코드를 입력하세요 >>> ", type);
	ushort tmp_id;
	scanf("%hu", &tmp_id);

	// 삭제할 아이템의 인덱스를 구함
	int index = find_base_by_id(pOldData, count, tmp_id);
	if (index < 0)
	{
		printf("잘 못 입력했습니다.");
		return count;
	}

	size_t new_count = count - 1;
	if (!new_count)
	{
		// 데이터가 한 개만 있었을 경우 배열 자체를 해제하고 0을 반환함
		free(pOldData);
		*ppData = NULL;
		return 0;
	}

	size_t new_size = sizeof(BASE_INFO) * new_count;
	BASE_INFO* pNewData = (BASE_INFO*)malloc(new_size);
	if (!pNewData) return count;

	int i = 0;
	for (int i = 0, j = 0; i < count; i++)
	{
		if (i != index) {
			memcpy(pNewData + j, pOldData + i, sizeof(BASE_INFO));
			j++;
		}
		


	}
	free(pOldData);
	*ppData = pNewData;

	return new_count;

}

size_t save_data(BASE_INFO pData[], size_t count, const char* filename)
{
	if (!pData || !count) {
		return 0;
	}

	FILE* fp = fopen(filename, "w");
	if (!fp) return 0;
	size_t ret = fwrite(pData, sizeof(BASE_INFO), count, fp);

	fclose(fp);

	return ret;
}

long long get_file_size(const char* filename) {
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (!fp) {
		printf(" 파일을 열 수 없음");
		return 0;
	}
	fseek(fp, 0, SEEK_SET); // 커서를 파일의 시작점으로 이동시킨다.
	fseek(fp, 1, SEEK_SET); // 커서를 파일의 시작점의 우로 1보 이동시킨다.
	fseek(fp, -1, SEEK_END); // 커서를 파일의 끝점에서 좌로 1보 이동시킨다.

	// 커서를 가장 끝 부분으로 이동 시킴
	fseek(fp, 0, SEEK_END);

	// 파일에서의 커서의 현재 위치를 알려줌
	long pos = ftell(fp);
	fclose(fp);

	return pos;
}

size_t load_data(BASE_INFO** ppData, const char* filename)
{
	if (!ppData) return 0;

	long filesize = get_file_size(filename);
	if (!filesize) return 0;

	BASE_INFO* pNewPart = (BASE_INFO*)malloc(filesize);
	if (!pNewPart) return 0;

	size_t count = 0;
	FILE* fp = fopen(PART_FILE, "r");
	if (fp)
	{
		fread(pNewPart, filesize, 1, fp);
		count = filesize / sizeof(BASE_INFO);
		*ppData = pNewPart;	// 메인 부서 배열 주소를 업데이트 해준다
		fclose(fp);
	}
	return count;
}

void print_base(BASE_INFO pBase[], size_t count, const char* type, bool isAnyKey)
{
	if (!pBase || !count) {
		return;
	}

	system("cls");
	printf("%s코드\t%s명\t\n", type, type);
	printf("=======================\n");
	for (size_t i = 0; i < count; i++) {
		printf("%8d\t%s\n", pBase[i].id, pBase[i].name);
	}

	printf("=======================\n");

	if (isAnyKey) {
		printf("계속하려면 아무키나 누르세요...\n");
		_getch();
	} 
	
	
}

int find_base_by_id(BASE_INFO pData[], size_t count, ushort id) 
{
	if (!pData || !count) return -1;

	for (size_t i = 0; i < count; i++) {
		if (pData[i].id == id) {
			return i;
		}
	}

	return -1;
}