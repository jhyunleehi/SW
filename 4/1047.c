/**************************************************************
    Problem: 1047
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
int call(int P[], int N) {
    int rtn;
    //printf("%d\n", N);
    if (P[N] != 0) return P[N];
    if ((N == 1)||(N==2)) return 1;
    P[N] = call(P,N-1) + call(P, N - 2);
    return P[N];
}
 
int main() {
    //freopen("data.txt", "r", stdin);
    int P[40] = { 0, };
    int N;
    scanf("%d", &N);
    printf("%d\n", call(P, N));
}
