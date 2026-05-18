#define _CRT_SECURE_NO_WARNINGS // msc custom 함수를 사용하지 않도록 도와줌

#include <stdio.h>  // standard inout output, 표준 입출력에 관련된 함수
#include<stdlib.h>  // 유틸리티 함수
#include<string.h>  // 문자열 처리에 관련된 함수
#include<time.h>

#define LOTTO_COUNT 6
#define LOTTO_MAX 45
#define LOTTO_ROWS 5

// Randomize
void randomize() {
    // randomize: 랜덤초기화
    // time(NULL): 이 컴퓨터의 현재 시간값
    time_t t;
    srand((unsigned int)time(NULL));   
}

// 순차 탐색 함수
// value를 arr에서 찾고, 있으면 해당 value의 index를 반환, 없으면 -1반환
int find_value(int arr[], int count, int value) {
    if (!arr || !count) return -1;
    for (int i = 0; i < count; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// 정렬을 하는 이유는 탐색을 빠르게 하기 위해서...
int binary_search(int arr[], int count, int value) {
    if (!arr || !count) return -1;

    int lo = 0;
    int hi = count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (value == arr[mid]) return mid;
        else if (value > arr[mid]) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// 중복된 값이 들어가지 않도록 1~45사이의 값을 구해야함
void make_random_array(int arr[], int count) { // 항상 배열의 크기를 넘겨주는 거 잊지 말기!
    if (!arr || !count) return;
    int tmp;
    int i = 0;
    while (i < count) {
        tmp = rand() % LOTTO_MAX +1;
        if (find_value(arr, count, tmp)) arr[i++] = tmp;
    }
}

void print_array(int arr[], int count) {
    if (!arr || !count) return;
    for (int i = 0; i < count; i++) printf("%2d ", arr[i]);
    printf("\n");
}

void exchange_potition(int* p1, int* p2) {
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// 정렬 알고리즘: Bubble Sort, Selection Sort, Insetrion Sort, Merge Sort, Quick Sort
void bubble_sort(int arr[], int count) {
    if (!arr || !count) return;
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                exchange_potition(&arr[j], &arr[j + 1]);
            }
        }
    }
}



void make_random_matrix(int(*arr)[LOTTO_COUNT], int rows) {
    for (int i = 0; i < rows; i++) {
        make_random_array(arr[i], LOTTO_COUNT);
        bubble_sort(arr[i], LOTTO_COUNT);
        
    }
}

int matched_count(int lotto[], int user[], int count) {
    int ret = 0;
    for (int i = 0; i < count; i++) {
        if (binary_search(lotto, count, user[i]) >= 0)  ret++;
    }
    return ret;
}

void print_matrix(int(*arr)[LOTTO_COUNT], int rows) {
    for (int i = 0; i < rows; i++) {
        print_array(arr[i], LOTTO_COUNT);

    }
}



// Lottery Simulator
int main()
{
    randomize();

    int lotto[LOTTO_COUNT] = {0};
    make_random_array(lotto, LOTTO_COUNT);
    bubble_sort(lotto, LOTTO_COUNT);

    printf("=== 당첨번호 ===\n");
    print_array(lotto, LOTTO_COUNT);

    int* ptr;

    printf("\n=== 구매자 번호===\n");
    // 구매자 번호, 2차원 배열 --> 각 원소들은 1차원 배열이다.
    int users[LOTTO_ROWS][LOTTO_COUNT] = { 0 };
    make_random_matrix(users, LOTTO_ROWS);
    for (int i = 0; i < LOTTO_ROWS; i++) {
        print_array(users[i], LOTTO_COUNT);
        int result = matched_count(lotto, users[i], LOTTO_COUNT);
        printf("당첨개수: %d개\n\n", result);
    }
    // print_matrix(users, LOTTO_ROWS);


    //// Stack형 Jagged Array
    //int arr1[5] = { 1,2,3,4,5 };
    //int arr2[3] = { 6,7,8 };
    //int arr3[4] = { 9, 10, 11, 12 };
    //int *arr4[3] = {arr1, arr2, arr3};  // Jagged Array

    int tmps[10] = { 1,2,3,4,5,6,7,8,9,10 };
    printf("%d \n", binary_search(tmps, 10, 8));



    // 2차원 배열 포인터
    //int (*p)[LOTTO_COUNT];
    //p = users;
    //p[0][0] = 0; // 이렇게 활용할 수 있음

    //p++; // 이런게 가능해짐 (row를 increment)
    
    return 0;
}