
#include <stdio.h>

int main()
{
    // 1 ~ 100까지의 모든 정수들을 저장하는 배열을 생성하여 데이터를 저장하세요
    short nums[100];    // 인덱수 : 0 ~ 99
    for (int i = 0; i < 100; i++)
    {
        nums[i] = i + 1;    // nums의 i번째 칸에 데이터 i를 대입
    }

    // nums배열의 모든 아이템들을 출력하세요
    for (int i = 0; i < 100; i++)
        printf("%hd ", nums[i]);

    printf("\n\n"); // 줄간격 벌리기
            
    // nums배열의 0번 인덱스의 아이템부터 짝수에 해당하는 인덱스들의 값을 출력하세요
    for (int i = 0; i < 100; i+=2)
        printf("%hd ", nums[i]);

    printf("\n\n"); // 줄간격 벌리기

    int scores[] = { 66, 75, 44, 92, 78, 56, 98, 88, 65, 83 };

    // scores 배열의 아이템들의 개수를 구하세요.
    // 배열의 길이(아이템들을 저장할 수 있는 공간 개수)를 구하는 공식: 
    // 배열의 바이트수 / 배열의 타입 ==> 배열의 길이(length)
    int len = sizeof(scores) / sizeof(int); 

    printf("scores배열의 크기: %llu bytes\n", sizeof(scores));
    printf("scores배열의 길이: %llu 개\n", len);

    // scores 배열의 모든 아이템들의 총 합과 평균을 구하세요
    int total = 0;  // 누적변수를 준비
    for (int i = 0; i < len; i++)
    {
        total += scores[i];
    }
    printf("합계: %d\n", total);
    float avg = total / (float)len;
    printf("평균: %.2f\n\n", avg);

    // scores에서 60보다 작은 값들의 번호와 값을 모두 출력하세요
    printf("scores배열에서 60보다 작은 값들 출력하기.\n");
    for (int i = 0; i < len; i++)
    {
        if (scores[i] < 60)
            printf("%d번: %d점\n", i+1, scores[i]);
    }

    // scores배열에서 평균보다 큰 점수의 번호와 점수를 모두 출력하세요
    printf("scores배열에서 평균이상의 값들 출력하기.\n");
    for (int i = 0; i < len; i++)
    {
        if (scores[i] >= avg)
            printf("%d번: %d점\n", i + 1, scores[i]);
    }

    // scores배열에서 가장 큰 점수의 번호와 점수를 출력하세요
    int max_index = 1;  // 첫번째 아이템의 번호는 0(번 인덱스) + 1이므로 1번임을 의미함
    int max = scores[0];    // 첫번째 값을 최대값으로 일단 가정
    for (int i = 1; i < len; i++)
    {
        if (max < scores[i])
        {
            max_index = i+1;
            max = scores[i];    // max값을 갱신
        }            
    }

    printf("scores배열에서 최대값의 번호와 점수 출력하기\n");
    printf("%d번: %d점\n", max_index, max);

    printf("\n");
    printf("정렬전: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", scores[i]);
    }
    printf("\n");
    // 배열의 값들의 정렬(버블 정렬)
    // 정렬 알고리즘: 버블, 선택, 삽입, 병합, 퀵, 힙
    for (int i = 0; i < len; i++)
    {
        for (int j=0; j<len-i-1; j++)
        {            
            if (scores[j] > scores[j + 1])
            {
                // 두값을 교환
                int tmp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tmp;
            }
        }
    }

    printf("정렬후: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", scores[i]);
    }
    printf("\n");


    return 0;
}
