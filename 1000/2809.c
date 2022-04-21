/**************************************************************
    Problem: 2809
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
void qsort(unsigned int map[], int S,int E) {   
    if (S >= E) return;
    int p = S, q = E;
    int v = map[S];
    p++;
    while (p<q) {
        while ( map[p] <= v) p++;
        while (map[q] > v ) q--;
        if (p < q) {
            int tmp = map[p];
            map[p] = map[q];
            map[q] = tmp;
        }
        //for (int j = 0; j <= E; j++) printf("[%d] ", map[j]);  printf("\n");
    }
    if (map[q] < v) {
        int tmp = map[q];
        map[q] = map[S];
        map[S] = tmp;
    }
    //for (int j = 0; j <= E; j++) printf("(%d) ", map[j]);  printf("\n");
    qsort(map, S, q-1);
    qsort(map, q+1, E);
}
 
int main() {
    unsigned int N;
    int k = 1;
    unsigned int map[1000] = { 0, };
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    int i = 0;
     
    while (k * k <= N) {
        if (N%k == 0) {
            map[i++] = k;
            if ( N/k != k) map[i++] = N / k;
        }
        k++;
        //for (int j = 0; j <= i; j++) printf("[%d] ", map[j]);  printf("\n");
    }
    qsort(map, 0, --i);
    i = 0;
    while (map[i]!= 0) {
        printf("%u ", map[i++]);
    }
 
    return 1;
}
