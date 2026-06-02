#pragma once

#define _CRT_SECURE_NO_WARNINGS		// Windows only

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <conio.h>	// Windows only

#define PART_FILE "part.dat"
#define LINK_FILE "link.dat"
#define EMPT_FILE "employee.dat"

#define EMPLOYEE_TITLE 사원
#define DEPARTMENT 부서
#define RANK_TITLE 직급
#define INFORMATION 정보

#define CREATE 입력
#define READ 조회
#define UPDATE 수정
#define DELETE 삭제

#define MAX_NAME 50

#define CLEAR_SCREEN system("cls")
#define CLEAR_BUFFER while (getchar() != '\n')	// 입력 버퍼 청소하기


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
} PART;

// 직급 정보
typedef struct {
	ushort id;
	char name[MAX_NAME];
} RANK;

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

void print_part(PART* pPart, size_t count);

size_t input_part(PART** ppNewPart, size_t count);

/// <summary> takes an input fom user and stores it the designated buffer
/// </summary>/// <param name="buffer"></param>/// <param name="len"></param>
void input(char* buffer, size_t len);


/// <summary>/// inserts department title at desired index /// </summary>/// <param name="ppNewPart"></param>/// <param name="count"></param>/// <param name="pos"></param>/// <returns></returns>
size_t input_part_insert(PART** ppNewPart, size_t count, int pos);