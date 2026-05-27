#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef struct {
    char name[FILENAME_MAX];
    uint power;
    uint speed;
} ITEM;

// File I/O

void save_text() {
    FILE* fp = NULL;
    // File mode: r, w, a, b, t
    // 파일 열기
    fp = fopen("test.txt", "wt");
    if (!fp) {
        printf(" 파일을 열 수 없음");
        return;
    }

    // POSIX: Console이라는게 있는데, stdout, stdin, stderr이 정의 되어있음

    fputs("Hello World\n", fp);
    fputs("세상아 안녕\n", fp);
    fputs("반갑다\n", fp);
    fprintf(fp, "올해는 %d년입니다.\n", 2026);

    fclose(fp);

}

void load_text() {
    FILE* fp = NULL;
    fp = fopen("test.txt", "rt");//질문!!!!!!!!!!!!!!!!!!!!!
    if (!fp) {//질문!!!!!!!!!!!!!!!!!!!!!
        printf("파일을 열 수 없습니다.");
        return;
    }

    char buf[8];
    while (1) {
        char* ret = fgets(buf, sizeof(buf), fp); //질문!!!!!!!!!!!!!!!!!!!!!
        if (!ret) break;
        printf("%s", buf);
        
    }

    fclose(fp);
}



// 파일의 크기 구하기
long long get_file_size(const char* filename) {
    FILE* fp = NULL;
    fp = fopen(filename, "r");
    if (!fp) {
        printf(" 파일을 열 수 없음");
        return 0;
    }

    // File cursor Handling
    // SEEK_SET: origin을 파일의 시작점으로 정한다.
    // SEEK_END: origin을 파일의 끝점으로 정한다.
    // SEEK_CUR: origin을 파일의 현재점으로 정한다.

    // _offset: 이동시킬 거리
    fseek(fp, 0, SEEK_SET); // 커서를 파일의 시작점으로 이동시킨다.
    fseek(fp, 1, SEEK_SET); // 커서를 파일의 시작점의 우로 1보 이동시킨다.
    fseek(fp, -1, SEEK_END); // 커서를 파일의 끝점에서 좌로 1보 이동시킨다.

    // 커서를 가장 끝 부분으로 이동 시킴
    fseek(fp, 0, SEEK_END);

    // 파일에서의 커서의 현재 위치를 알려줌
    long pos = ftell(fp);
    fclose(fp);

    return pos;
}

size_t write_items(ITEM items[], int count) {
    FILE* fp = NULL;
    fp = fopen("items.dat", "wb");
    if (!fp) {
        printf("파일을 열 수 없습니다.");
        return 0;
    }

    
    size_t ret = fwrite(
        items, // 저장할 데이터가 들어있는 버퍼(items[] 배열)
        sizeof(ITEM),   // 배열의 각 요소의 크기
        count,          // elements의 개수
        fp              // 파일핸들
        );


    fclose(fp);

    return ret;
}

size_t load_items(ITEM items[], int count) {
    FILE* fp = NULL;
    fp = fopen("items.dat", "rb");
    if (!fp) {
        printf("파일을 열 수 없습니다.");
        return 0;
    }


    size_t ret = fread(
        items, // 저장할 데이터가 들어있는 버퍼(items[] 배열)
        sizeof(ITEM),   // 배열의 각 요소의 크기
        count,          // elements의 개수
        fp              // 파일핸들
    );


    fclose(fp);

    return ret;
}




int main()
{
    //save_text();
    // load_text();
    printf("File size: %ld\n", get_file_size("test.txt"));


    ITEM item[10];

   /* strcpy(item[0].name, "ak-47");
    item[0].power = 100;
    item[0].speed = 150;

    strcpy(item[1].name, "k2");
    item[1].power = 100;
    item[1].speed = 150;

    printf("반환값: %llu\n", write_items(item, 2));*/

    size_t ret = load_items(item, 2);
    for (size_t i = 0; i < ret; i++) {
        printf("Name: %s\n", item[i].name);
        printf("Power: %u\n", item[i].power);
        printf("Speed: %u\n", item[i].speed);
    }

    // float arr[10] = {1.F, 2.F, 3.F, 4.F, 5.F, 6.F, 7.F, 8.F, 9.F, 10.F};
    //int arr[3]; // static array
    
    // 동적 메모리 할당(Dynamic Memory Allocation)

    // int* parr = NULL: OR
    int* parr = (int*)malloc(/*메모리의 크기를 바이트 단위로 저장*/sizeof(int) * 3);
    // parr 주소에 Lock을 걸어서 다른 application의 접근을 차단한다.
    if (!parr) {
        printf("메모리 할당 실패");
        return -1;
    }

    //calloc(
    //    sizeof(int),    // element의 크기
    //    3               // 길이
    //)


    parr[0] = 1;
    parr[1] = 2;
    parr[2] = 3;

    // 자체적으로 기존의 parr을 해제하고 새롭게 할당한다
    if (parr) parr = (int*)realloc(parr, sizeof(int) * 4);

    // Lock을 해제한다
    if (parr) {
        // parr에 할당이 성공적으로 된 경우에만 해제가능
        free(parr);
        parr = NULL;
    }


    return 0;
}
