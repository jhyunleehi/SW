/**************************************************************
    Problem: 2814
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
int main() {
    char str[31];
    int  N=0;
    //freopen("data.txt", "r", stdin);
    scanf("%s", str);
    int i = 0;
    while (str[i] != NULL) {        
        N = (N << 1) + str[i++] - '0';        
    }
    printf("%d\n", N);
    return 1;
}
