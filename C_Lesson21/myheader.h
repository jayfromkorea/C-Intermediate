#define _CRT_SECURE_NO_WARNINGS

// #pragma once와 아래 #ifndef #define #define와 같음
#ifndef ___C_LESSON_21_HEADER_H__
#define ___C_LESSON_21_HEADER_H__

#include <stdio.h>
#include <string.h>

#define CHECK_PARAM(x)	if (!x) return;

// 이렇게 헤더들을 custom 헤더파일을 설정할 수 있음
#define PI 3.14F

const int MAX_LEN = 255;

// 형 재정의
typedef unsigned int	AGE;
typedef unsigned int	ID;

typedef struct {
	int top;
	int bottom;
	int left;
	int right;
} RECT;

typedef RECT* LPRECT;//LP는 long pointer라는 의미임

typedef struct {
	int x;
	int y;
} POINT;

// 구조체(Structure)
// 학생 시험 성적
typedef struct {	// Score을 지우면 anonymous 구조체가 됨
	// 구조체 멤버의 정의
	ID id;
	char name[MAX_LEN];
	unsigned int math;
	unsigned int kor;
	unsigned int eng;
	unsigned int total;
	float avg;
} Score;	// 이와 같이 anonymous 구조체를 만들고 typedef을 사용할 수 있음

typedef Score* PSCore;

AGE input_age();
void input_score(PSCore psc);	/*psc --> [in, out]*/
void print_score(PSCore psc);	/*psc --> [in]*/

// 함수의 원형 정의(함수의 선언)
void print_hello();

#endif