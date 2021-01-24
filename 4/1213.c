#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
void qsort(int *N, int S, int E) {
    //for (int i = S; i <= E; i++) printf("[%d]", *(N + i)); printf("\n");
    if (S >= E) return;
    int m = (S + E) / 2;
    int p = S;
    int q = E;
    int temp;
    while (p <= q) {
        while (*(N + p) < *(N + m)) p++;
        while (*(N + q) > *(N + m)) q--;
        if (p <= q) {
            temp = *(N + p);
            *(N + p) = *(N + q);
            *(N + q) = temp;
                        p++; q--;
        }
         
    }
    if(S<q) qsort(N, S, q);
    if(E>p) qsort(N, p, E);
}
 
int main() {
    int N;
    int *X, *Y;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    X = (int*)malloc(sizeof(int)*N + 1);
    Y = (int*)malloc(sizeof(int)*N + 1);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", X + i, Y + i);
    }
    qsort(X, 0, N-1);
    qsort(Y, 0, N-1);
    int x[2], y[2];
    x[0] = *X;
    y[0] = *Y;
    x[1] = *(X + (N - 1));
    y[1] = *(Y + (N - 1));
    printf("%d\n", (x[1] - x[0]) * (y[1] - y[0]));
}
