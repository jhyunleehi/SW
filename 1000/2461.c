/**************************************************************
    Problem: 2461
    User: jhyunlee
    Language: C++
    Result: Success
    Time:57 ms
    Memory:1876 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct fw *pflow;
typedef struct fw {
    int S;
    int E;
};
 
int N;
 
void qsort(struct fw *pfw, int L, int R) {
    //printf("%d %d \n", L, R);
    if (L >= R) return;
    int p = L;
    int q = R;
    int v = (pfw + (L + R) / 2)->E;
    while (p <= q) {
        while ((pfw+p)->E < v) p++;
        while ((pfw+q)->E > v) q--;
        if (p <= q) {
            //swap
            struct fw temp = *(pfw + p);
            *(pfw + p) = *(pfw + q);
            *(pfw + q) = temp;
            p++; q--;
 
        }
    }   
    if (L < q) qsort(pfw, L, q);
    if (R > p) qsort(pfw, p, R);
}
 
 
int main() {    
    pflow pf;
    //freopen("data.txt", "r", stdin);
    int S1, S2, E1, E2;
    scanf("%d", &N);
    pf = (pflow)malloc(sizeof(fw)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &S1, &S2, &E1, &E2);
        (pf+i)->S = S1 * 100 + S2;
        (pf+i)->E = E1 * 100 + E2;
    }
    /*
    for (int i = 0; i < N; i++) {
        printf("%d %d  \n", (pf + i)->S, (pf + i)->E);        
    }
    */
 
    qsort(pf, 0, N - 1);
    /*
    for (int i = 0; i < N; i++) {
        printf("%d %d  \n", (pf + i)->S, (pf + i)->E);
    }
    */
    int fromDay = 301;
    int from = 0;
    int maxEnd = 0;
    int endDay = 0;
    bool choose=false;
    int count = 0;
    while (1) {
        for (int i = from; i < N; i++) {
            if ((pf + i)->S <= fromDay) {             
                if (endDay < (pf + i)->E) {
                    from = i;
                    endDay = (pf + i)->E;
                    maxEnd = i;
                    choose = true;                  
                }               
            }       
        }
        if (choose) {
            fromDay = (pf + from)->E;
            count++;
            choose = false;
        }else{
            break;
        }
        if (endDay >= 1201) break;
    }
    if (endDay < 1201) 
        printf("%d\n", 0);
    else
        printf("%d\n", count);
}
