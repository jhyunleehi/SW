/**************************************************************
    Problem: 2074
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    int **map = (int**)malloc(sizeof(int*)*(N + 1));
    for (int i = 0; i <= N; i++) *(map + i) = (int*)malloc(sizeof(int)*(N + 1));
    int k = 1;
    int y = N;
    int x = N / 2+1;
 
    while (k <= N * N) {
        *(*(map + y) + x) = k;
        if (k%N == 0) {
            if (y == 1) y = N;
            else y = y - 1;
        } else {
            y = y + 1; x = x - 1;
        }       
        if (x == 0) { x = N; }
        if (y == N+1) { y = 1;}
        k++;
    }
 
    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= N; j++)
            printf("%d ", *(*(map + i) + j));
        printf("\n");
    }
    return 1;
}
