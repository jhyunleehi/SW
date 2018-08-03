/**************************************************************
    Problem: 1692
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>;
 
int main() {
    int A, B;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &A);
    scanf("%d", &B);
    int Div = 1;
    while (B / Div != 0) {
        Div *= 10;
        int RM = B % Div;
        int Cnt = RM / (Div / 10);
        printf("%d\n", A*Cnt);
    }
    printf("%d\n", A*B);
 
    return 1;
}
