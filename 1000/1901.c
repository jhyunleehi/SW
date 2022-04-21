/**************************************************************
    Problem: 1901
    User: jhyunlee
    Language: C++
    Result: Success
    Time:111 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int isPrimeNum(int M) {
    if (M <= 1) return 0;
    int last = M / 2;
    for (int i = 2; i <= last; i++) {
        if (M%i == 0) return 0;
    }
    return 1;
}
 
int main() {
    int N=0;
    int M = 0;
    int brk = 0;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &M);
        for (int j = 0; j < M / 2; j++) {
            if (j == 0) {
                if (isPrimeNum(M)) { printf("%d\n", M); break; }
            }
            else {
                if (isPrimeNum(M - j)) { brk = 1; printf("%d ", M - j); }
                if (isPrimeNum(M + j)) { brk = 1; printf("%d", M + j); }
                if (brk == 1) {
                    printf("\n");
                    break;
                }
            }
             
        }
        brk = 0;
    }
}
