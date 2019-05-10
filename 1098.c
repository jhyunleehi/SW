/**************************************************************
    Problem: 1098
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    //freopen("data.txt", "r", stdin);
    int M[10] = { 6,2,5,5,4,5,6,3,7,6 };
    char *str = (char*)malloc(sizeof(char) * 50 + 1);
    scanf("%s", str);
    int sum = 0;
    int i = 0;
    while (*(str + i) != '\0') {
        sum+=M[*(str + i) - '0'];
        i++;
    }
    printf("%d\n", sum);
}
