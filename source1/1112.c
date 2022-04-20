/**************************************************************
    Problem: 1112
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}
 
int main() {
    int N;
    float S, E;
    float M;
    int P[3][2];
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    S = 0; E = N;
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &P[i][0], &P[i][1]);
    }
         
    for (int i = 0; i < 3; i++) {
        if (P[i][0] == P[i][1]) continue;
        if (P[i][0] > P[i][1]) swap(&P[i][0], &P[i][1]);
        M = (P[i][0] + P[i][1]) / 2.0;
        if ((M - S) < (E - M)) {
            S = M; 
            for (int j = i; j < 3; j++) {
                if (P[j][0] > P[j][1]) swap(&P[j][0], &P[j][1]);
                if (P[j][0] < M)  P[j][0] = M + (M - P[j][0]);
                if (P[j][1] < M)  P[j][1] = M + (M - P[j][1]);
            }
        }
        else if ((M - S) >= (E - M)){
            E = M;
            for (int j = i; j < 3; j++) {
                if (P[j][0] > P[j][1]) swap(&P[j][0], &P[j][1]);
                if (P[j][0] > M) P[j][0] = M - (P[j][0] - M);
                if (P[j][1] > M) P[j][1] = M - (P[j][1] - M);
            }
        }
    }
    printf("%.1f \n", E - S);
 
    return 1;
}
