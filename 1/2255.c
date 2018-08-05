/**************************************************************
    Problem: 2255
    User: jhyunlee
    Language: C++
    Result: Success
    Time:3 ms
    Memory:1376 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int get_gcd(unsigned int A, unsigned int B) {
    if (A < B) {
        int temp = B;
        B = A;
        A = temp;
    }
    while (A%B != 0) {
        A = A % B;
        int temp = A;
        A = B; B = temp;
    }
    //printf("[%d]\n", B);
    return B;
}
 
int main() {
    int N;
    bool visite = false;
    unsigned int L[10000] = { 0, };
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    //int *M = (int*)malloc(sizeof(int)*(N + 1));
    int *M = new int[N + 1];
    int *C = (int*)malloc(sizeof(int)*(N + 1));
    for (int i = 1; i <= N; i++) scanf("%d", M + i);
    for (int i = 1; i <= N; i++) *(C + i) = 0;       
 
    int ans = 1;
    int j = 0;
    for (int i = 1; i <= N; i++) {
        int k = i;      
        int cnt = 1;
        while (C[k] == 0) {         
            C[k] = 1;           
            k = *(M + k);           
            if( C[k]==0) cnt++;         
            //printf("k:[%d] cnt:[%d]\n ", k, cnt);
            //for (int i = 1; i <= N; i++) printf("[%d]", *(C + i));
            //printf("\n");
        }
        //printf("[%d]\n", cnt);
        if (cnt > 1) L[j++] = cnt;
    }
    j = 0;
    unsigned int gcd, lcm;
    gcd = lcm = L[0];
    while (L[j] != 0) {
        gcd = get_gcd(gcd, L[j]);
        lcm = lcm / get_gcd(lcm, L[j]) * L[j];
        j++;
    }
    //printf("%d\  %dn", gcd, lcm);
    printf("%d\n", lcm);
    return 1;
}
