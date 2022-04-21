 
#include<stdio.h>
#include<malloc.h>
 
int get_gcd(int A, int B) {
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
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    int *List = (int*)malloc(sizeof(int)*N + 1);
    for (int i = 0; i < N; i++)
        scanf("%d", &List[i]);
    int gcd, lcm;
    gcd = lcm = List[0];
    for (int i = 1; i < N; i++) {
        gcd=get_gcd(gcd, List[i]);
        lcm = (lcm * List[i] )/ get_gcd(lcm, List[i]);      
    }
    printf("%d %d", gcd, lcm);
    return 1;
}
