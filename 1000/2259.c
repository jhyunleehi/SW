/**************************************************************
    Problem: 2259
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N = 0;
    int L[7];
    int D[7];
    int maxL = 0, maxH = 0;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < 7; i++) {
        scanf("%d %d", &D[i], &L[i]);
        if ((D[i] == 1) || (D[i] == 2))
            if (maxL < L[i]) maxL = L[i];
        if ((D[i] == 3) || (D[i] == 4))
            if (maxH < L[i])maxH = L[i];
    }
    int fsize = 0;
    for (int i = 0; i < 6; i++) {
        if (i == 5) {
            fsize += L[i] * L[0];
        }
        else
            fsize += L[i] * L[i + 1];
        //printf("%d %d \n", i, fsize);
    }
    fsize = fsize - (maxL*maxH)*2;
    printf("%d\n", fsize*N);
    return 1;
}
