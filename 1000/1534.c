/**************************************************************
    Problem: 1534
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
void get2(int N, int D) {
    if (N == 0) return;
    get2(N / D, D);
    int R = N % D;
    switch (R) {
    case 10:
        printf("A");
        break;
    case 11:
        printf("B");
        break;
    case 12:
        printf("C");
        break;
    case 13:
        printf("D");
        break;
    case 14:
        printf("E");
        break;
    case 15:
        printf("F");
        break;
    default:
        printf("%d", R);
        break;
    }
}
 
int main() {
    int A, B;
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &A, &B);
    switch (B) {
    case 2:
        get2(A,2);
        break;
    case 8:
        get2(A, 8);
        break;
    case 16:
        get2(A, 16);
        break;      
    }
 
    return 1;
}
