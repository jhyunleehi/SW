/**************************************************************
    Problem: 1620
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int P, N,M;
    char str[101];
    int  Num[30] = { 0, };
    char del = '-';
    //freopen("data.txt", "r", stdin);
    scanf("%s", str);
    int i = 0;
    int j = 1;
    int maxcnt = 0;
    int cnt = 0;
    while (str[i] != '\0') {
        if (str[i] != del)  { 
            Num[j] = Num[j] * 10 + str[i] - '0';
            cnt++;
        }
        else {
            j++;
            if (maxcnt < cnt) maxcnt = cnt;
            cnt = 0;
        }
        //printf("%d %d\n", cnt, maxcnt);
        i++;
    }
    N = j;
    //while (j >= 1) {
    //  printf("%d\n", Num[j--]);
    //}
    scanf("%d %d", &P, &M);
    if ((M > N) || ( 9999 < Num[M]) || (4 < maxcnt)) {
        printf("INPUT ERROR!\n");
        return 0;
    }   
     
    int NN = Num[M];
    int DD = 1;
    int LOG = 0;
    while (NN / DD) {
        DD *= 10; 
        LOG++;
    }
    //printf("[%d] [%d]\n", LOG, DD);
    if (LOG <= 4) LOG = 4;
    int Result = 0;
    for (int i = LOG; i >= 1; i--) {
        int div = 1;
        for (int j = 1; j < i; j++) div = div * 10;
        int R = NN / div;
        NN = NN % div;
        R = (R + P)%10;     
        Result += R * div;
    }
    printf("%04d\n", Result);
 
    return 1;
     
}
