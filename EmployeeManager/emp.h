#pragma once

#define _CRT_SECURE_NO_WARNINGS		// Windows only

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdbool.h>
#include <conio.h>	// Windows only

#define S_PART	"부서"
#define S_RANK	"직급"

#define PART_FILE "part.dat"
#define RANK_FILE "rank.dat"
#define EMPL_FILE "employee.dat"

#define EMPLOYEE_TITLE 사원
#define DEPARTMENT 부서
#define RANK_TITLE 직급
#define INFORMATION 정보

#define CREATE 입력
#define READ 조회
#define UPDATE 수정
#define DELETE 삭제

#define MAX_NAME 50

#define FREE(x) if (x){ free(x); x = NULL; }


typedef unsigned short ushort; // 0~ 65535

// 사원 정보
typedef struct {
	ushort id;
	char name[50];
	ushort part;
	ushort rank;
	float score;
} EMPLOYEE;

// 부서 정보
typedef struct {
	ushort id;
	char name[MAX_NAME];
} BASE_INFO;

typedef BASE_INFO PART;
typedef BASE_INFO RANK;

//// 직급 정보
//typedef struct {
//	ushort id;
//	char name[MAX_NAME];
//} RANK;

// 함수의 원형 정의
int employee_procedure();

/// <summary>
/// 메뉴를 화면에 출력하는 함수
/// /// </summary>
void show_menu();

/// <summary>
/// 메뉴를 선택하고 해당 메뉴 아이템을 반환하는 함수
/// </summary>
/// <returns> 선택된 메뉴의 값 </returns>
int select_menu();

size_t input_employee(EMPLOYEE** ppEmp, size_t count, PART* pPart, size_t part_count, RANK* pRank, size_t rank_count);



void print_base(BASE_INFO pData[], size_t count, const char* type, bool isAnyKey=true);

size_t input_base(BASE_INFO** ppData, size_t count, const char* type);

/// <summary>
/// 파일에 저장함
/// </summary>
/// <param name="pPart"></param>
/// <param name="count"></param>
/// <returns></returns>
size_t save_data(BASE_INFO pData[], size_t count, const char* filename);
size_t save_employee(EMPLOYEE* pEmp, size_t emp_count);

size_t load_data(BASE_INFO** ppData, const char* filename);
size_t load_employee(EMPLOYEE** ppEmp);

fpos_t get_file_size(const char* filename);

long long find_employee_by_id(EMPLOYEE pEmp[], size_t count, ushort id);
int find_base_by_id(BASE_INFO pData[], size_t count, ushort id);

void update_employee(EMPLOYEE pEmp[], size_t count, PART pPart[], size_t part_count, RANK pRank[], size_t rank_count);
void update_base(BASE_INFO* pData, size_t count, const char* type);
const char* find_base_name_by_id(BASE_INFO* pData, size_t count, ushort id);
void print_employee(EMPLOYEE* pEmp, size_t count, PART* pPart, size_t part_count, RANK* pRank, size_t rank_count, bool isAnyKey = true);

size_t delete_base(BASE_INFO** ppData, size_t count, const char* type);
size_t delete_employee(EMPLOYEE** ppEmp, size_t count, BASE_INFO pPart[], size_t part_count, BASE_INFO pRank[], size_t rank_count);


