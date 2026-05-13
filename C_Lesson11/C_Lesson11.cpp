#include <stdio.h>

// 배열(Array) ---> 고정 길이 배열
// 같은 종류의 데이터들을 연속적으로 여러개 저장할 수 있는 공간
// 가장 기본적인 자료구조 형태

int main()
{
    int num = 5;        // 64비트 windows os, 4바이트
    // 배열의 선언
    int nums[3];    // 4바이트 x 3개 ===> 12바이트
        
    // 인덱싱을 이용하여 배열의 각각의 아이템에 접근할 수 있다.
    nums[0] = 10;   // nums배열의 첫번째 아이템에 10을 대입
    nums[1] = 20;
    nums[2] = 30;
    // nums[3] = 40;   // 에러, 

    printf("nums배열의 첫번째 아이템의 값: %d\n", nums[0]);
    printf("nums배열의 두번째 아이템의 값: %d\n", nums[1]);
    printf("nums배열의 세번째 아이템의 값: %d\n", nums[2]);

    // 배열의 초기화
    char arr1[5] = {10, 20, 30, 40, 50};
    double arr2[10] = { 1., 2., 3., 4., 5., 6., 7., 8., 9., 10. };
    // 배열의 개수를 지정하지 않고 선언할때는 반드시 초기화와함께 선언되어야 한다!
    short arr3[] = {1,2,3,4,5,6,7}; // 7칸짜리 short형 배열

    // sizeof(변수) : 변수의 메모리 할당 크기를 정수로 알려줌
    // sizeof(타입) : 타입의 메모리 할당 크기를 정수로 알려줌
    // sizeof(배열명): 해당 배열의 메모리 할당 크기를 정수로 알려줌
    printf("num 변수의 메모리 할당 크기: %llu bytes\n", sizeof(num));
    printf("int 타입의 메모리 할당 크기: %llu bytes\n", sizeof(int));
    
    printf("nums 배열의 크기: %llu bytes\n", sizeof(nums));
    printf("arr1 배열의 크기: %llu bytes\n", sizeof(arr1));
    printf("arr2 배열의 크기: %llu bytes\n", sizeof(arr2));
    printf("arr3 배열의 크기: %llu bytes\n", sizeof(arr3));


    // arr1에서 4번째 아이템 출력하기
    printf("arr1 배열의 4번째 아이템: %hhd\n", arr1[3]);
    printf("arr2 배열의 10번째 아이템: %f\n", arr2[9]);
    printf("arr3 배열의 6번째 아이템: %hd\n", arr3[5]);

    // 배열의 모든 아이템들을 0으로 초기화 <-- 배열의 개수를 지정하여 선언해야 한다.
    float arr4[5] = { 0 };
    printf("arr4 배열의 5번째 아이템: %f\n", arr4[4]);


    return 0;
}
