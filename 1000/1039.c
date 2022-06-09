/**************************************************************
    Problem: 1039
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N = 0;    
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    N++;
    printf("%d\n", N*N - ((N*N) - N) / 2);
}
