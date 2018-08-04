/**************************************************************
    Problem: 1071
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include <stdio.h>
#include <malloc.h>
 
int main() {
    int N;
    int M;
    int *List;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    List = (int *)malloc(sizeof(int)*(N + 1));
    for (int i = 0; i < N; i++) scanf("%d", &List[i]);
    scanf("%d", &M);
    int i = 0;
    int r1 = 0, r2 = 0;
    while (i < N) {
        if (M % List[i] == 0) r1 += List[i];
        i++;
    }
    i = 0;
    while (i < N) {
        if (List[i] % M == 0) r2 += List[i];
        i++;
    }
 
    printf("%d\n", r1);
    printf("%d\n", r2);
     
    return 1;
}
