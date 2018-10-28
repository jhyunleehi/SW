/**************************************************************
    Problem: 1352
    User: jhyunlee
    Language: C++
    Result: Success
    Time:6 ms
    Memory:7744 kb
****************************************************************/
 
 
/*
양팔 저울
1. 추를 왼쪽, 오른쪽, 선택하지 않는 3가지 경우로 나눠서 전체 탐색
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct Node *link;
typedef struct Node{
    int N;
    link L;
    link R;
};
 
int N, M;
int *C;
int *G;
int *Map;
link btree;
char visited[31][40001*2];
 
bool btree_add(link * bt, int n) {
    if ((*(bt))->N == n) return true;
    if ((*(bt))->N > n) {
        if ((*(bt))->L != NULL) return btree_add(&(*bt)->L, n);
        else {
            link temp = (struct Node*)malloc(sizeof(struct Node));
            temp->N = n;
            temp->L = NULL;
            temp->R = NULL;
            (*(bt))->L = temp;
        }
    }
    else {
        if ((*bt)->R != NULL) return btree_add(&(*bt)->R, n);
        else {
            link temp = (struct Node*)malloc(sizeof(struct Node));
            temp->N = n;
            temp->L = NULL;
            temp->R = NULL;
            (*(bt))->R = temp;
        }
    }
}
 
bool btree_find(link *bt, int n) {
     if ((*(bt))->N == n) return true;
     if (((*(bt))->N > n) && ((*(bt))->L != NULL)) return btree_find(&(*(bt))->L, n);
     if (((*(bt))->N < n) && ((*(bt))->R != NULL)) return btree_find(&(*(bt))->R, n);
     return false;
}
 
void btree_print (link *bt) {
    printf("[%d]", (*bt)->N);
    if ((*(bt))->L != NULL) btree_print(&(*(bt))->L);
    if ((*(bt))->R != NULL) btree_print(&(*(bt))->R);
}
 
void call(int n, int w) { //n: 추단계, w: weight   
    //printf("call: %d %d \n", n, w);
    int i = 0;  
    bool dup = false;
    //여기 부분을 단축이 필요하다.
    if (!btree_find(&btree, w)) btree_add(&btree, w);   
    if (n >= N) return;
    if (!visited[n + 1][w - *(C + n) + 40000]) {
        call(n + 1, w - *(C + n)); //왼쪽 선택
        visited[n + 1][w - *(C + n) + 40000] = 1;
    }
    if (!visited[n + 1][w + *(C + n) + 40000]) {
        call(n + 1, w + *(C + n)); //오른쪽 선택
        visited[n + 1][w + *(C + n) + 40000] = 1;
    }
    if (!visited[n + 1][w + 40000]) {
        call(n + 1, w);           //선택하지 않음 
        visited[n + 1][w + +40000] = 1;
    }
}
 
void qsort(int L, int R) {
    //printf("sort: %d %d \n", L, R);
    int p = L;
    int q = R;
    int v = *(Map + (L + R) / 2);
    while (p <= q) {
        while (*(Map+p) < v) p++;
        while (*(Map+q) > v) q--;
        if (p <= q) {
            int temp = *(Map + p);
            *(Map + p) = *(Map + q);
            *(Map + q) = temp;
            p++; q--;
        }
    }
    if(L<q) qsort(L, q);
    if(R>p) qsort(p, R);
}
 
bool find(int s, int e, int n) {
    if (s > e) return false;
    int m = ((s + e) / 2);
    int v = *(Map + m);
    if (v == n) return true;
    if (v > n)
        return find(s, m-1, n);
    else
        return find(m + 1, e, n);
}
 
int main() {
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    C = (int*)malloc(sizeof(int)*N + 1);
 
    Map = (int*)malloc(sizeof(int)*(1024*1024) + 1);    
    for (int i = 0; i < 1024*1024; i++) *(Map + i) = 0;
 
    for (int i = 0; i < N; i++) scanf("%d", (C + i));
    //for (int i = 0; i < N; i++)    printf("%d", *(C + i)); printf("\n");
    scanf("%d", &M);
     
    G = (int*)malloc(sizeof(int)*M + 1);
    for (int i = 0; i < M; i++)scanf("%d", G + i);
    btree = (struct Node*)malloc(sizeof(struct Node));
    btree->N = 0;
    btree->L = NULL;
    btree->R = NULL;
    call(0, 0);
    //btree_print(&btree);
 
    //int length = 0;
    //while (*(Map + length) != 0) length++;
    //qsort(0, length -1);
    for (int i = 0; i < M; i++) {
        if ( btree_find(&btree, *(G + i)) ) 
            printf("Y ");
        else
            printf("N ");
    }
}
