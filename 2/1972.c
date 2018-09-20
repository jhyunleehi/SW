/**************************************************************
    Problem: 1972
    User: jhyunlee
    Language: C++
    Result: Success
    Time:41 ms
    Memory:1484 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
void quick1(int *M, int Left, int Right) {  
    int L = Left;
    int R = Right;
    int temp;
    if (L >= R) return;
    int P = *(M+(L + R) / 2);
    while (L <= R) {
        while (*(M + L) < P) L++;
        while (*(M + R) > P) R--;
        if (L <= R) {
            temp = *(M + L);
            *(M + L) = *(M + R);
            *(M + R) = temp;
            L++; R--;
        }
    }
    if(Left<R) quick1(M, Left, R);
    if(L<Right) quick1(M, L, Right);
}
 
void quick2(int *M, int Left, int Right) {
    int L = Left;
    int R = Right;
    int temp;
    if (L >= R) return;
    int P = *(M + (L + R) / 2);
    while (L <= R) {
        while (*(M + L) > P) L++;
        while (*(M + R) < P) R--;
        if (L <= R) {
            temp = *(M + L);
            *(M + L) = *(M + R);
            *(M + R) = temp;
            L++; R--;
        }
    }
    if (Left<R) quick2(M, Left, R);
    if (L<Right) quick2(M, L, Right);
}
 
int main() {
    int N;
    int C;
    int *M;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%d", &C);
    M = (int*)malloc(sizeof(int)*N + 1);
    for (int i = 0; i < N; i++) {
        scanf("%d", (M + i));       
    }
    if (C == 0)//increse
        quick1(M, 0, N - 1);
    else
        quick2(M, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d\n", *(M + i));
    }
    return 0;
}
