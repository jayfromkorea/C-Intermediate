#include "myheader.h"

size_t get_file_size(const char* filename) {
	FILE* fp = NULL;
	fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed opening the file\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);

    fclose(fp);

    return pos;
}

ITEM* read_items_from_file(const char* filename) {
	ITEM* items = NULL;
	FILE* fp = NULL;
    const char* error_message = "";
    int error_code = 0;

    size_t file_size = get_file_size(filename);
    size_t element_size = sizeof(ITEM);
    size_t len = file_size / element_size;
    
	fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open the file:(\n");
        return NULL;
    }

    items = (ITEM*)malloc(file_size);
    if (!items) {
        printf("Failed to allocate memory");
        return NULL;
    }

    fread(items, element_size, len, fp);

	fclose(fp);

	return items;
}

int main()
{
    size_t file_size = get_file_size("items.dat");
    size_t item_len = sizeof(ITEM);
    size_t len = file_size / item_len;
    printf("필요한 배열의 길이: %llu\n", len);

    int ret = 0;// main 함수의 리턴 코드 정의
    const char* error = NULL;

    ITEM* items = NULL;
    items = read_items_from_file("items.dat");



    for (size_t i = 0; i < len; i++) {
        printf("Name: %s\n", items[i].name);
        printf("Power: %u\n", items[i].power);
        printf("Speed: %u\n", items[i].speed);
    }




RELEASE_AREA:

    if (items) {
        free(items);
    }

    if (error) {
        printf("Error: %s\n", error);
    }

    return ret;
}