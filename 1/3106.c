/**************************************************************
    Problem: 3106
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
void get2(long long N, int D) {
    if (N == 0) return;
    get2(N / D, D);
    int R = N % D;  
    if( R<10)    
        printf("%c", R+'0');
    else
        printf("%c", (R-10) + 'A');     
}
 
int main() {
    int A, B;
    char str[80];
    //freopen("data.txt", "r", stdin);
    scanf("%d", &A);
    while (A != 0) {
        scanf("%s %d", str, &B);
        int i = 0;
        long long int  N=0;
        while (str[i] != NULL) {
            if (str[i] >= 'A')
                N = N * A + str[i] - 'A'+10;
            else
                N = N * A + str[i] - '0';
            i++;            
        }
        //printf("[%lld] [%d] \n", N, B);
        if (N == 0) 
            printf("0");
        else
            get2(N, B);
        printf("\n");
 
        scanf("%d", &A);
    }
    return 1;
}
