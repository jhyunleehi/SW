/**************************************************************
    Problem: 2858
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    char str[100001];
    //freopen("data.txt", "r", stdin);
    scanf("%s", str);
    int i = 0;
    int N = 0;
    int M = 0;
    while (str[i] != NULL) {
        //printf("%c", str[i]);
        if (str[i] == '(' && str[i + 1] == ')') {
            M = M + N;
            i++; i++;
        }
        else {
            if (str[i] == '(') N += 1;
            if (str[i] == ')') { N -= 1;  M += 1; }
            i++;
        }
        //printf("%d %d \n", N, M);
    }
    M = M + N;
    printf("%d\n",M);
}
