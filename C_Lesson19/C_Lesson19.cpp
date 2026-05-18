#include <stdio.h>
#include <string.h>

// 문자열과 포인터
void print_string(const char* sz) {
    printf("sz문자열의 길이: %llu\n: ", strlen(sz));
    size_t len = strlen(sz);
    for (int i = 0; i < len; i++) {
        if (sz[i] >= 'a' && sz[i] <= 'z') {
            printf("%c", (sz[i] - 32));
        }
        else {
            printf("%c", sz[i]);
        }
        //sz문자열의 모든 내용들을 전부 대문자로 출력하세요
    }
    printf("\n");
}

// 문자열 배열을 받아서 해당 문자열의 글자를 모두 대문자로 변환하는 함수를 구현하세요
void capitalaize() {

}

int main()
{
    char sz1[] = "Hello World";
    printf("sz1문자열의 길이: %llu\n", strlen(sz1));
    printf("sz1배열의 길이: %llu\n", sizeof(sz1));
    sz1[0] = 'h';
    sz1[5] = 'w';
    printf("%s\n", sz1);

    const char* psz1 = "Nice To Meet You";  // 이 경우 psz1이 아니라 문자열 자체가 const임
    printf("%s\n", psz1);                   // 그렇기 때문에 문자열을 char을 임의로 바꿀 수 없음
    psz1 = "See You Next Time";
    printf("%s\n", psz1);
    // 32

    print_string(psz1);

    // 공백을 포함한 문자열 입력받기
    char name[50] = { 0 };
    fgets(name, 50, stdin);
    size_t len = strlen(name);
    name[len - 1] = '\0';
    printf("%s\n", name);


    return 0;

}
