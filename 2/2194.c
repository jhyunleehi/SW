/**************************************************************
    Problem: 2194
    User: jhyunlee
    Language: C++
    Result: Success
    Time:131 ms
    Memory:1328 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct W {
    int w;
    unsigned long C; //단가
    unsigned long Y; //물량
};
 
int main() {
    int N; //계산이 필요한 Week
    int S; //1주일 보관료
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &S);
    W *week = (W*)malloc(sizeof(W)*N);
    int *M = (int*)malloc(sizeof(int)*N); //해당 week에 필요한 최소 값
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &(week + i)->C, &(week + i)->Y);
        (week + i)->w = i;       
    }
 
    double ans = 0;
    double A, B, D;
    for (int i = 0; i < N; i++) {// week 0 부터 N week 까지
        D = (1.0)*((week + i)->C * (week + i)->Y);
        for (int j = i; j >= 0; j--) {
            A = ((week + j)->C * (week + i)->Y)*(1.0);
            B = ((week + i)->Y) * S*(i-j)*(1.0);         
            if (D > A+B) D = (A+B)*(1.0) ;
        }       
        ans += D;
        //printf("%d [%.0f] [%.0f] %.0f %.0f \n", i, A, B, D, ans);
    }   
    printf("%.0f\n", ans);
    return 0;
}
