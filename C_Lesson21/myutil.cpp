#include "myheader.h"

void print_hello() {
    printf("Hello World\n");
}

AGE input_age() {
    printf("나이를 입력하세여 >>> ");

    AGE age;
    scanf("%u", &age);

    return age;
}

void input_score(Score* psc) {
    CHECK_PARAM(&psc);
    // Score sc = {0}; // 구조체의 내용을 모두 0으로 초기화
    // char array 때문임 --> 문자열의 쓰레기 값 발생할 수 있기 때문임

    printf("번호를 입력하세요 >>> ");
    scanf("%u",&psc->id);

    char tmp;
    scanf("%c", &tmp);

    printf("이름를 입력하세요 >>> ");
    fgets(psc->name, MAX_LEN - 1, stdin);
    size_t len = strlen(psc->name);
    psc->name[len - 1] = 0;   // '\n'를 0으로 바꿔줌

    printf("점수를 입력하세요: ");
    scanf("%u %u %u", &psc->kor, &psc->eng, &psc->math);

    psc->total = psc->kor + psc->math + psc->eng;
    psc->avg = psc->total / 3.F;

}

void print_score(Score* psc) {
    printf("번호\t이름\t국어\t수학\t영어\t총점\t평균\n");
    printf("%d\t%s\ts\t%u\t%u\t%u\t%u\t%.2f\n", psc->id, psc->name, psc->kor, psc->math, psc->eng, psc->total, psc->avg);
}