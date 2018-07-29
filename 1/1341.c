/**************************************************************
    Problem: 1341
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int S, E;
    //freopen("data.txt", "r", stdin);
    while (!(-1 == scanf("%d %d", &S, &E))) {
        if ((S<2||S>9) || (E<2||E>9)) printf("INPUT ERROR!\n");
        else
        for (int D = S; (E > S) ? D <= E:D >= E; (E > S) ? D++ : D--) {
            for (int i = 0; i <= 2; i++) {
                for (int j = 1; j <= 3; j++) {
                    printf("%d * %d = %2d   ",D,i*3+j, D*(i*3+j) );
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}
