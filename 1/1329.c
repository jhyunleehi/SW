/**************************************************************
    Problem: 1329
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include <stdio.h>
#include <malloc.h>
 
int main() {
    int N;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    if ((N>100 || N % 2 == 0)) printf("INPUT ERROR!\n");
    else
    for (int i = 1; i <= N; i++) {
        if (i <= N / 2) {
            for (int j = 1; j < i; j++) printf(" ");
            for (int k = 1; k <= (i * 2) - 1; k++) printf("*");
            printf("\n");
        }
        else {
            //printf("--------\n");
            for (int j = 1; j <= (N-i) ; j++) printf(" ");
            int s = ((i - 1) - (N / 2))*2;
            for (int k = 1; k <= N-s; k++) printf("*");
            printf("\n");
        }
 
    }
    return 1;
}
