/**************************************************************
    Problem: 2071
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N, M;
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    int **map = (int **)malloc(sizeof(int *)*(N + 1));
    for (int i = 0; i <= N; i++)
        *(map + i) = (int *)malloc(sizeof(int)*(N + 1));
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            *(*(map + i) + j) = 0;
    switch (M) {
    case 1:
        for (int i = N; i >= 1; i--) {
            int L = (N - i + 1);
            for (int j = 1; j <= L; j++) {
                if (j==1) *(*(map + i) + j) = 1;
                else if (j == L) *(*(map + i) + j) = 1;
                else
                    *(*(map + i) + j) = *(*(map + (i+1)) + j) + *(*(map + (i + 1)) + (j-1));
            }
        }
        for (int i = N; i >= 1; i--) {
            for (int j = 1; j <= (N - i + 1); j++)
                printf("%d ", *(*(map + i) + j));
            printf("\n");                           
        }
        break;
    case 2:
        for (int i = 1; i <=N; i++) {
            int L = i;
            for (int j = 1; j <= L; j++) {
                if (j == 1) *(*(map + i) + j) = 1;
                else if (j == L) *(*(map + i) + j) = 1;
                else
                    *(*(map + i) + j) = *(*(map + (i - 1)) + j) + *(*(map + (i - 1)) + (j - 1));
            }
        }
        for (int i = N; i >= 1; i--) {
            for(int k=1; k<=(N - i); k++)
                printf(" ");
            for (int j = 1; j <= i; j++)
                printf("%d ", *(*(map + i) + j));
            printf("\n");
        }
        break;
    case 3:
        for (int i = N; i >= 1; i--) {
            int L = N-i+1;
            for (int j = 1; j <= L; j++) {
                if (j == 1) *(*(map + j) + i) = 1;
                else if (j == L) *(*(map + j) + i) = 1;
                else
                    *(*(map + j) + i) = *(*(map +j) + (i+1)) + *(*(map + (j - 1)) + (i + 1));
            }
        }
        for (int i = N; i >= 1; i--) {           
            for (int j = 1; j <= N - i + 1; j++)
                printf("%d ", *(*(map + i) + j));
            printf("\n");
        }
 
        break;
    }
    return 1;
}
