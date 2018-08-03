/**************************************************************
    Problem: 1430
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int A, B, C;
    int R = 0;
    int M[10] = { 0, };
    char nstr[12];
    //freopen("data.txt", "r", stdin);
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    R = A * B * C;  
    sprintf(nstr, "%d", R);
    int i = 0;
    while (nstr[i] != '\0') {       
        M[nstr[i++] - '0']++;       
    }
    i = 0;
    while (i <= 9) {
        printf("%d\n", M[i++]);
    }
    return 1;
}
