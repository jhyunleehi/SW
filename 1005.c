#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
int isPrimeNum(int N) {
    if (N <= 1) return -1;
    int last = N / 2;
    for (int i = 2; i <= last; i++) {
        if (N%i == 0) return -1;
    }
    return 0;
}
 
int main() {
    int M;
    int *N; 
    int max_prime = 0;;
    int prime_num=0;
    int last;
    //freopen("input.dat", "r", stdin);
    scanf("%d", &M);
    N = (int*)malloc(sizeof(int)*(M + 1));
    for (int i = 0; i < M; i++) {
        scanf("%d", (N + i));
        last = *(N + i) ;
        for (int j = last; j >= 2; j--) {
            if (*(N + i) % j != 0) continue;
            int result = isPrimeNum(j);
            //printf("[%d] [%d] [%d]\n", i, j, result);
            if (result == 0) {
                if (j > max_prime) {
                    max_prime = j;
                    prime_num = *(N + i);
                    //printf("---> %d %d \n", max_prime, prime_num);
                }
                break;
            }
        }
    }
    printf("%d\n", prime_num);
}
