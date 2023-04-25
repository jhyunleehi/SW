/**************************************************************
    Problem: 1402
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N, K;
    int Div = 1;
    int cnt = 0;
    //freopen("data.txt", "r", stdin);
    scanf("%d %d ", &N, &K);
    while (Div <= N ) {
        if (N%Div == 0) cnt++;
        if (cnt == K) break; else Div++;
    }
    if (cnt != K) printf("0");
    else printf("%d\n", Div);
 
 
    return 1;
}
