/**************************************************************
    Problem: 1658
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int A, B;
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &A, &B);
    int N = (A < B) ? A : B;
    int i = 1;
    int ans = 1;
    while (i <= N) {
        if (A%i == 0 && B%i == 0) ans = i;
        i++;
    }
    printf("%d\n", ans);
    printf("%d\n", A*B / ans);
    return 1;
}
