/**************************************************************
    Problem: 1641
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N, M;
    //freopen("data.txt", "r", stdin);
    while (!(-1 == scanf("%d %d", &N, &M))) {
        if ((N>100 || N % 2 == 0) || (M<1 || M>4)) printf("INPUT ERROR!\n");
        else
            switch (M) {
            case 1: {
                int D = 1;
                int S = 0, E = 0;
                for (int i = 0; i < N; i++) {
                    S = E + 1; E = S + i;
                    int S1 = S;
                    int E1 = E;
                    for (int j = 1; j <= D; j++) printf("%d ", i&1?E1--:S1++ );
                    printf("\n");
                    D++;
                }
            }
                    break;
            case 2:
                {
                int S = 0;
                int E = 2*(N-1);
                int D = 0;
                for (int i = 1; i<= N; i++) {                    
                    for (int j = 1; j <= S; j++) printf("  ");
                    for (int k = S; k <= E; k++) printf("%d ",D);
                    printf("\n");
                    S++; E--;
                    D++;
                }
                }
                break;
            case 3: {
                int S = 0;
                for (int i = 1; i <= N; i++) {
                    i <= (N / 2 + 1) ? S++ : S-- ;                   
                    for (int k = 1; k <= S; k++) printf("%d ",k);
                    printf("\n");
                }
            }
                break;
            }
 
             
 
    }
    return 1;
}
