/**************************************************************
    Problem: 1719
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
        if ((N>100 || N%2 == 0) || (M<1 || M>4)) printf("INPUT ERROR!\n");
        else
            switch (M) {
            case 1:
                for (int i = 1; i <= N; i++) {                   
                    int S = (i <= (N / 2)) ? i : (N+1) - i;
                    for (int j = 1; j <= S; j++)
                        printf("*");
                        //printf("*%d %d ", i, j);
                    printf("\n");
                }
                break;
            case 2:
                for (int i = 1; i <= N; i++) {
                    int S = (i <= (N / 2) ? (N/2+1) - i : i - (N/2+1));
                    for (int j = 1; j <= S; j++) printf(" ");
                    for (int k = 1; k <= (N/2+1)-S ; k++) printf("*"); 
                    printf("\n");
                }
                break;
            case 3:
                for (int i = 1; i <= N; i++) {
                    int S = (i <= (N / 2) ? i - 1 : N-i);
                    for (int j = 1; j <= S; j++) printf(" ");
                    for (int k= 1; k<=N-S*2;k++) printf("*");
                    printf("\n");
 
                }
                break;
            case 4:
                for (int i = 1; i <= N; i++) {
                    if (i <= (N / 2)) {
                        int S = i - 1;
                        for (int j = 1; j <= S; j++) printf(" ");
                        for (int k = 1; k <= N/2+2-i; k++) printf("*");
                        printf("\n");
                    }
                    else
                    {
                        int S = i - (N / 2);
                        for (int j = 1; j <= (N/2); j++) printf(" ");
                        for (int k = 1; k <= S; k++) printf("*");
                        printf("\n");
                    }
                }
                break;
        }
 
    }
    return 1;
}
