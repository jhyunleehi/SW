/**************************************************************
    Problem: 1038
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<ctime>
int main() {
    //freopen("Text.txt", "r", stdin);
    char A[101], B[2], C[101];
    int  a_cnt(0), c_cnt(0);
    scanf("%s", A);
    scanf("%s", B);
    scanf("%s", C);
    while (A[a_cnt] != '\0') a_cnt++;
    while (C[c_cnt] != '\0') c_cnt++;
    a_cnt--; c_cnt--;
    switch (B[0]) {
    case '*':
        printf("1");
        for (int i = 1; i <= (a_cnt + c_cnt); i++) {
            printf("0");
        }
        break;
    case '+':
 
        int max = (a_cnt > c_cnt) ? a_cnt : c_cnt;
        int min = (a_cnt < c_cnt) ? a_cnt : c_cnt;
        min = max - min;
        if (min == 0) printf("2"); else printf("1");
 
        for (int i = 1; i <= max; i++) {
            if (i == min) printf("1");
            else printf("0");
        }
        break;
    }
    printf("\n");
}
