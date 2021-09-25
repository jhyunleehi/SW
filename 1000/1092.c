#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<ctime>
 
#define D_VAL 20091024
typedef unsigned long long ll;
ll temp[50];
 
int main() {
    //freopen("Text.txt", "r", stdin);
    //clock_t t0 = clock();
    int A, B, C;
    ll ss(0);   
    int odd(0),count(0);
    scanf("%d %d", &A, &B);
    if (A > D_VAL) ss = A % D_VAL;
    else ss = A;
    while (B > 1) {      
        if (B % 2 == 1) {
            temp[count] = ss;
            count++;
        }
        ss = (ss% D_VAL)*(ss% D_VAL) % D_VAL;       
        B = B / 2;
        //printf("B:%d  ss:%d\n", B, ss);
    }
    for (int c = 0; c < count; c++) {
        ss = (ss*temp[c]) % D_VAL;
    }   
        if(A==0) ss=1;
    printf("%llu\n", ss);
    //printf("%.3f\n", (float)(clock() - t0) / CLOCKS_PER_SEC);
}
