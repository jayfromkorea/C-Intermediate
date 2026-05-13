#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // standard input output, 표준 입출력(파일)
#include <string.h>

// stdout: 표준 출력 장치
// stderr: 표준 에러 출력 장치
// stdin : 표준 입력 장치

int main()
{
    char sz[] = "Hello World";  // 문자열
    printf("%s\n", sz); // 문자열의 출력

    // 문자열의 길이
    printf("sz 문자열의 길이: %llu\n", strlen(sz));

    //// 여러개의 데이터를 하나의 scanf로 입력받기
    //int i, j, k;
    //scanf("%d %d %d", &i, &j, &k);
    //printf("%d\t%d\t%d\n", i, j, k);

    // 문자열의 입력
    char str[20];   // 문자열 버퍼(Buffer)
    //printf("문자열을 입력하세요 >>> ");  // 프롬프트 출력
    //scanf("%s", str);                   // 문자열 입력, 공백 문자를 입력받을 수 없음
    //printf("입력된 문자열: %s\n", str); // 문자열의 출력

    // 공백문자가 포함된 문자열을 입력받기
    // fgets: 파일로부터 문자열을 입력바는 함수
    //printf("문자열을 입력하세요 >>> ");
    //fgets(str, 20, stdin);  // stdin으로부터 최대 20-1 알파벳글자를 str에 입력받음
    //size_t length = strlen(str);
    //str[length - 1] = 0;    // LF(Line Feed)제어 문자를 null terminated character로 수정해줌
    //printf("입력된 문자열: %s\n", str); // 문자열의 출력    

    //length = strlen(str);   // LF가 제거된 문자열의 길이를 다시 구함
    //printf("입력된 문자열의 길이: %llu\n", length);
    /*for (int i = 0; i < length; i++)
    {
        printf("(%hhd)", str[i]);
    }*/

    // 문자열의 비교: strcmp
    char sz1[] = "Hello";
    char sz2[] = "Hello";
    // if (sz1 == sz2) 문자열의 비교는 이와같이 하지 않는다!!!
    if (strcmp(sz1, sz2) == 0 )
        printf("sz1(%s)과 sz2(%s)는 같음\n", sz1, sz2);
    else
        printf("sz1(%s)과 sz2(%s)는 다름\n", sz1, sz2);

    
    // 문자열의 대입
    // sz1 = "Nice"; // 배열 기반 문자열에서 대입 연산자를 이용하여 문자열을 대입할 수 없음
    strcpy(sz1, "Nice"); // Nice라는 문자열을 sz1에 대입
    printf("sz1 == %s\n", sz1);

    // strcpy의 주의사항
    // 배열의 길이보다 문자열의 길이가 더 큰 문자열을 대입할때는 런타임 에러가 발생함
    /*strcpy(sz1, "Nice to meet you"); 
    printf("sz1 == %s\n", sz1);*/

    // strchr: 문자열에서 특정 문자를 찾는 함수
    // strstr: 문자열에서 특정 문자열을 찾는 함수
    // strcat: 문자열 추가

    // 문자열 보간(String Interpolation)
    int age = 20;
    char name[] = "아이유";
    // 안녕하세요, 내 이름은 ***이고, 나이는 **살입니다

    // char형 100칸짜리 배열을 생성하고, 모두 0으로 초기화
    char intro[100] = { 0 };
    sprintf(intro, "안녕하세요, 내 이름은 %s이고, 나이는 %d살입니다", name, age);
    printf("%s\n", intro);
    
    return 0;
}
