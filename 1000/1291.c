
#include <stdio.h>
#include<malloc.h>
 
int main() {
 
    int S, E;
    int K = 0;
    int R = 0;
    freopen("data.txt", "r", stdin);
    //이것은 주석으로 처리해야 
     
    while (-1 != scanf("%d %d", &S, &E)) {
        if ((S < 2 || S>9) || (E < 2 || E>9)) {
            printf("INPUT ERROR!\n");
        }
        else
        {
            for (int i = 1; i <= 9; i++) {
                for (int j = S; (S < E) ? j <= E : j >= E; (S < E) ? j++ : j--) {
                    printf("%d * %d = %2d   ", j, i, j*i);
                }
                printf("\n");
            }
        }
 
    }
}
