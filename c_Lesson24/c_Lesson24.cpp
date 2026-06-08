#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 함수의 포인터
// 
// 함수의 포인터를 정의하는 방법
typedef int (*CALC)(int, int);

typedef struct {
    int id;
    char name[20];
    int score;
} SCORE;

int compare_id(const void* a, const void* b)
{
    SCORE* p1 = (SCORE*)a;
    SCORE* p2 = (SCORE*)b;

    return p1->id > p2->id ? 1 : -1;
}

int compare_id(const void* a, const void* b)
{
    SCORE* p1 = (SCORE*)a;
    SCORE* p2 = (SCORE*)b;

    return strcmp(p1->name, p2->name);
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

void print_operation(int a, int b, CALC func)
{
    printf("%d\n", func(a, b));
}

// qsort함수에 전달될 함수 형식
typedef int(*compare_func)(const void*, const void*);

int compare_number(const void* a, const void* b)
{
    int* p1 = (int*)a;
    int* p2 = (int*)b;

    return *p1 > *p2 ? 1 : -1;
}


int main()
{
    CALC add_func = add;
    CALC subtract_func = subtract;

    printf("%d\n", add(1, 2));
    printf("%d\n", add_func(1, 2));

    printf("%d\n", subtract(1, 2));
    printf("%d\n", subtract_func(1, 2));

    print_operation(1, 2, add);
    print_operation(1, 2, subtract);

    int arr[] = { 7, 4, 8, 1, 3, 2 };
    qsort(arr, 6, sizeof(int), compare_number);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    SCORE scorces[3] = {
        {1, "jake", 100},
        {1, "joy", 50},
        {1, "jay", 79},
    };

    return 0;
}