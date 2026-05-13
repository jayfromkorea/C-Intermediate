#include <stdio.h>

// 배열의 주소와 길이를 전달
// const를 사용하여 함수가 arr의 내용을 임의적으로 변경하는 것을 방지
void print_array(const short arr[], unsigned int len) {   // short* arr로 parameter을 설정해도 무방함
    for (int i = 0; i < len; i++) {
        printf("%hd ", *(arr++));   // ++는 sizeof(short)만큼 증가함
    }

    printf("\n");
}

void multiply_value(double arr[], unsigned int len) {
    for (int i = 0; i < len; i++) {
        arr[i] *= 5;
    }
}

//int* multiply_result() {
//    int arr[] = { 10, 20, 30, 40, 50 };
//    for (int i = 0; i < 5; i++) {
//        arr[i] *= 5;
//    }
//
//    return arr;
//}

int main()
{
    // 배열명은 상수(constant)이다
    short arr1[] = { 10, 20, 30, 40 ,50, 60, 70 };
    short* p1 = arr1;
    double arr2[] = { 1., 2., 3. };
    short num = 100;

    // 배열의 길이 구하기
    unsigned int len = sizeof(arr1) / sizeof(short);

    for (int i = 0; i < len; i++) {
        printf("%hd ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%hd ", p1[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%hd ", *(arr1 + i));
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%hd ", *(p1 + i));
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%hd ", *(p1++));
    }

    printf("\n");
    print_array(arr1, len);

    int len2 = sizeof(arr2) / sizeof(double);

    /*int* m_arr = multiply_result();
    for (int i = 0; i < 5; i++) {
        printf("d% ", m_arr[i]);
    }*/
    
    return 0;
}
