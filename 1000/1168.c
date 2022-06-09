/**************************************************************
    Problem: 1168
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
 
int A, B, N;
int main(){
    //freopen("Text.txt", "r", stdin);  
    while (1) {
        scanf("%d %d %d", &A, &B, &N);
        if (A == 0) break;
        printf("%d\n", A / B);
        A = (A % B)*10;
        if (A == 0) break;
        for (int i = 1; i <= N; i++) {
            if (A < B) {
                A = A * 10;
                printf("0");
            }else if (A >= B) {
                printf("%d", A / B);
                A = (A % B) * 10;
            }
            if (A == 0) {               
                break;
            }
            if ((i % 10 == 0) &&(i != N)) printf("\n");;
        }       
        printf("\n");
    }
}
