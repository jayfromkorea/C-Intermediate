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

#define MAX_NAME 50


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