#include <stdio.h>
int N, D[10000001];

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);   
    D[1]=5;
    int i=2;
    for (i=2; i<=N; i++){
        D[i]=D[i-1]+i*3+1;    
        D[i]=D[i]%45678;
    }
    printf("%d",D[N]);
}