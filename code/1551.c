#include <stdio.h>
int N,M, D[21],A[21];

void call(int n){
    for (int i=0; i<n-1; i++){
        D[i]=D[i+1]-D[i];
    }    
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    int ans=0;
    int i=0;
    for (i = 0; i < N-1; i++){
        scanf("%d,", &D[i]);        
    }    
    scanf("%d",&D[i]);
    
    for (int i=0, n=N; i<M; i++, n--){
        call(n);
    }

    for (i=0; i<(N-M)-1; i++){
        printf("%d,",D[i]);
    }
    printf("%d",D[i]);
}