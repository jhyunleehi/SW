/**************************************************************
    Problem: 2085
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int B, A, C;
    int cntB, cntA;
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &B, &A);
     
    cntB = B / 4;
    cntB -= B / 100;
    cntB += B / 400;
    //printf("%d\n", cntB);
 
    cntA = A / 4;
    cntA -= A / 100;
    cntA += A / 400;
    //printf("%d\n", cntA);
 
    printf("%d\n", cntB-cntA);
     
 
    return 1;
}
