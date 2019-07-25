/**************************************************************
    Problem: 1042
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<ctime>
 
int N;
char N1[16], N2[16];
 
int str_len(char *str) 
{
    int size(0);
    while (*(str+size) != '\0') {
        size++;
    }
    return size;
}
 
int main() {
    //freopen("Text.txt", "r", stdin);
    //clock_t t0 = clock();
    scanf("%d", &N);
    scanf("%s", N1);
    scanf("%s", N2);
    int len1 = str_len(N1);
    int len2 = str_len(N2);
    int val1(0), val2(0), sum(0), p(1);
    for (int i = len1 - 1; i >= 0; --i) {
        if (N1[i] >= '0'  && N1[i] <= '9')  val1 += p * (N1[i] - '0');
        if (N1[i] >= 'A'  && N1[i] <= 'Z')  val1 += p * (N1[i] - 'A' +10);
        p = p * N;
    }
    p = 1;
    for (int i = len2 - 1; i >= 0; --i) {
        if (N2[i] >= '0'  && N2[i] <= '9')  val2 += p * (N2[i] - '0');
        if (N2[i] >= 'A'  && N2[i] <= 'Z')  val2 += p * (N2[i] - 'A'+10);
        p = p * N;
    }
    printf("%d\n", sum = val1 + val2);
    int t(0), i(0);;
    char r[16] = { 0, };
    while (sum >= N) {
        t = sum % N;
        sum = sum / N;
        if (t >= 0 && t <= 9)  r[i] = t + '0';
        if (t >= 10 && t <= 36) r[i] = (t-10) + 'A';
        i++;
    }
    if (sum >= 1 && sum <= 9)  r[i] = sum + '0';
    if (sum >= 10 && sum <= 36) r[i] = (sum-10) + 'A';
 
    for (i = i; i >= 0; --i) {
        printf("%c", r[i]);
    }
    //printf("\n%.2f \n", (clock() - t0) / CLOCKS_PER_SEC);
}
