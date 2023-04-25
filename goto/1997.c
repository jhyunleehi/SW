/**************************************************************
    Problem: 1997
    User: jhyunlee
    Language: C++
    Result: Success
    Time:4 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int fibo(int A, int B, int M, int N, int cnt){
    //printf("[%d][%d][%d][%d][%d] \n",A, B, M, N,cnt);
    if (((A + B == M) &&(cnt==N))) {
        //printf("**[%d]", N);
        return 1;
    }
    if (A + B > M)   return 0;
    if (N<cnt) return 0;
    if (fibo(B, A + B, M, N, cnt+1)) return 1;
    else return 0;
}
 
int main() {
    int N= 0;
    int M = 0;
    int A, B;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%d", &M);
    // A*(D-3) + B*(D-1) = M
    for (int i = 1; i <= M ; i++) {
        for (int j = i; j <= M ; j++) {
            if (fibo(i, j, M, N, 3)) { 
                printf("%d\n%d\n", i, j); 
                return 1; 
            }
        }
    }
}
