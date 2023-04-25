/**************************************************************
    Problem: 2641
    User: jhyunlee
    Language: C++
    Result: Success
    Time:31 ms
    Memory:16824 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
 
typedef struct box {
    int dist;
    int from;
    int to;
    int load;
};
 
int V;
int MAX;
int N;
box *B;
 
void makeMap(int **M, int N) {
    int F, T, L;
    for (int i = 0; i < N; i++) {
        F = (B + i)->from;
        T = (B + i)->to;
        L= (B + i)->load;
        *(*(M + F) + T) = L;
    }
}
 
void qsort(struct box *Load, int Left, int Right) {
    if (Left >= Right) return;
    int p = Left;
    int q = Right;
    int v = (Load + ((Left + Right) / 2) )->dist;  //dist=from -to 거리 증가순으로 정렬   
    while (p <= q) {
        while ((Load+p)->dist < v) p++;
        while ((Load+q)->dist > v) q--;
        if (p <= q) {
            //swap
            box temp = *(Load + p);
            *(Load + p) = *(Load + q);
            *(Load + q) = temp;
            p++; q--;
        }
    }
    if (Left < q) qsort(Load, Left, q);
    if (Right > p) qsort(Load, p, Right);        
}
 
 
int main() {
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &V, &MAX);
    scanf("%d", &N);
    int **Map = (int**)malloc(sizeof(int*)*(V+1));
    for (int i = 0; i <= V; i++) {
        *(Map + i) = (int *)malloc(sizeof(int)*(V+1));
        for (int j = 0; j <= V; j++)
            *(*(Map + i) + j) = 0;
    }
 
    B = (box*)malloc(sizeof(struct box)*N);
     
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &(B + i)->from, &(B + i)->to, &(B + i)->load);
        (B + i)->dist = ((B + i)->to)*10000+ ((B + i)->from);
    }
     
    qsort(B, 0, N - 1);
    makeMap(Map, N);
    /*
    for (int i = 0; i < N; i++) {
        printf("[%d][%d][%d][%d] \n", (B + i)->dist, (B + i)->from, (B + i)->to, (B + i)->load);
    }
    */
    /*
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            printf("%2d ", *(*(Map + i) + j));
        }
        printf("\n");
    }
    */
         
    int ans = 0;    
    int *W = (int *)malloc(sizeof(int)*(V + 1));//해당위치에서 실려 있는 량
    for (int i = 0; i <= V; i++) *(W + i) = 0;
    int F, T, L, D, before_load,optimized_load;
 
    for (int i = 0; i < N; i++) {
        F = (B + i)->from;
        T = (B + i)->to;
        L = (B + i)->load;
        before_load = 0;
        for (int j = F; j < T; j++) {
            if (before_load < *(W + j)) 
                before_load = *(W + j);
        }
        optimized_load = 0;
        optimized_load = (MAX - before_load) < (B + i)->load ? (MAX - before_load) : (B + i)->load;
        //printf("(%3d) [%3d] [%3d] [%3d] ", i, before_load, optimized_load, ans);
        for (int k = F; k < T; k++) {
            *(W + k) += optimized_load;
        }
        ans += optimized_load;
        //for (int m = 0; m <= V; m++) printf("%2d ", *(W + m));
        //printf("\n");
    }
    printf("%d\n", ans);
 
    return 0;
}
