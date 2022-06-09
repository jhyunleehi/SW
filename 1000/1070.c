/**************************************************************
    Problem: 1070
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct map *pmap;
typedef struct map {
    int M[5][5];
    int X;
    int Y;
    int A;
    int B;
};
 
void make_M(struct map *N) {
    for(int j=1; j<=4; j++){
        N->M[0][j] = N->X % 10;
        N->X = N->X / 10;
    }
    for (int j = 1; j <= 4; j++) {
        N->M[j][0] = N->Y % 10;
        N->Y = N->Y / 10;
    }   
}
 
void make_AB(struct map *N) {
    N->A = 0;
    N->B = 0;
    N->M[0][0] = 0;
 
    for (int a = 1; a <= 4; a++) {
        for (int b = 1; b <= 4; b++) {
            if (N->M[a][0] != N->M[0][b]) {
                N->M[a][b] = 0;
            }else{
                N->M[a][b] = 1;
                if (a == b) 
                    N->A++;
                else
                    N->B++;
            }
        }
    }
    /*
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            printf("[%d]", N->M[i][j]);
        }
        printf("\n");
    }
    */
    printf("%dA%dB\n", N->A, N->B);
}
 
 
int main() {
    //freopen("data.txt", "r", stdin);
    pmap N = (pmap)malloc(sizeof(struct map));
    scanf("%d %d", &(N->X), &(N->Y));
    make_M(N);
    make_AB(N);
 
}
