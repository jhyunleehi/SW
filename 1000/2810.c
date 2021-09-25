/**************************************************************
    Problem: 2810
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
    int N1 = A;
    int N2 = B;
    while (A%B != 0) {
        int temp = A % B;
        A = B;
        B = temp;
    }
    printf("%d\n", (N1 / B) * (N2 / B));
 
    return 1;
}
