/**************************************************************
    Problem: 1998
    User: jhyunlee
    Language: C++
    Result: Success
    Time:14 ms
    Memory:1484 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N = 0;
    int M = 0;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    int *A = (int *)malloc(sizeof(int)*N+1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &M);
        *(A + i) = M;
    }
    int up = 1, down = 1;
    int max = 1;
    for (int i = 1; i < N; i++) {
        if (*(A + i) == *(A + i + 1)) { 
            up += 1;  down += 1;
            if (max <= up || max <= down) max = (up >= down) ? up : down;
        }
        else {
            if (*(A + i) < *(A + i + 1)) {up += 1; down = 1;}
            if (*(A + i) > *(A + i + 1)) {down += 1; up = 1;}
            if (max <= up || max <= down) max = (up >= down) ? up : down;
        }
        //printf("%d %d [%d] [%d] [%d]\n", *(A + i), *(A + i+1), up, down, max);
    }
    printf("%d\n", max);
    return 1;
}
