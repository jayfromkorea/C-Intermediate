#include "myheader.h"

// 파일의 크기 구하기
long long get_file_size(const char* filename) {
    FILE* fp = NULL;
    fp = fopen(filename, "r");
    if (!fp) {
        printf(" 파일을 열 수 없음");
        return 0;
    }
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

// 파일로부터 items 읽기
// 파일에 items 저장하기
// items에 데이터 추가하기
// items에 데이터 삭제하기

ITEM* read_items_from_file(const char* filename, size_t* plen) {
    ITEM* items = NULL;
    FILE* fp = NULL;

    // 파일 크기를 구함 --> 읽어들일 버퍼의 크기
    size_t file_size = get_file_size(filename);

    // 파일을 열고
    fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    // 동적메모리 할당
    items = (ITEM*)malloc(file_size);
    if (!items) {
        fclose(fp);
        return NULL;
    }

    *plen = file_size / sizeof(ITEM);
    fread(items, sizeof(ITEM), *plen, fp);

    // fread(items, file_size, 1, fp);
    //fread(items, sizeof(ITEM), len, fp);
    // 위의 방식과 밑의 방식과 같음. 밑에가 야매임
    // 동적으로 할당받은 배열에 파일의 데이터를 통으로 읽어들임
    //fread(items, file_size, 1, fp);

    // 파일을 닫고
    fclose(fp);

    // 할당받아서 데이터를 로드한 버퍼 주소를 반환
    return items;
}

// pp는 2차원 포인터 : 1차원 포인터의 주소를 가질 수 있다.
size_t read_items_from_file(const char* filename, ITEM** ppitems) {
    
    if (!filename || !ppitems) {
        // Bad Request
        return 0;
    }

    FILE* fp = NULL;

    // 파일 크기를 구함 --> 읽어들일 버퍼의 크기
    size_t file_size = get_file_size(filename);

    // 파일을 열고
    fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    // 동적메모리 할당
    *ppitems = (ITEM*)malloc(file_size);
    if (!*ppitems) {
        fclose(fp);
        return NULL;
    }

    size_t len = file_size / sizeof(ITEM);
    fread(*ppitems, sizeof(ITEM), len, fp);

    // fread(items, file_size, 1, fp);
    //fread(items, sizeof(ITEM), len, fp);
    // 위의 방식과 밑의 방식과 같음. 밑에가 야매임
    // 동적으로 할당받은 배열에 파일의 데이터를 통으로 읽어들임
    //fread(items, file_size, 1, fp);

    // 파일을 닫고
    fclose(fp);

    

    // 할당받아서 데이터를 로드한 버퍼 주소를 반환
    return len;
}




int main()
{
    /*size_t file_size = get_file_size("items.dat");
    size_t item_len = sizeof(ITEM);
    size_t len = file_size / item_len;
    printf("필요한 배열의 길이: %llu\n", len);*/

    size_t len = 0;
    int ret = 0;// main 함수의 리턴 코드 정의
    const char* error = NULL;

    printf("len = %llu\n", len);

    ITEM* items = NULL;
    len = read_items_from_file("items.dat", &items);
    
    printf("len = %llu\n", len);

    for (size_t i = 0; i < len; i++) {
        printf("Name: %s\n", items[i].name);
        printf("Power: %u\n", items[i].power);
        printf("Speed: %u\n", items[i].speed);
    }
   

    if (items) {
        free(items);
    }

    if (error) {
        printf("Error: %s\n", error);
    }

    return ret;
}