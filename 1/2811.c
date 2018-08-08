/**************************************************************
    Problem: 2811
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N;
    //freopen("data.txt", "r", stdin);
    for (int i = 1; i <= 5; i++) {
        scanf("%d", &N);
        if (N == 1) {
            printf("number one\n");
            continue;
        }
        int j = 2;
        bool P = false;
        while (j*j <= N) {
            if (N%j == 0) {
                printf("composite number\n");
                P = true;
                break;
            }
            j++;
        }
        if (!P) printf("prime number\n");
    }
 
    return 1;
}
