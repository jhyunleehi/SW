#include <stdio.h>
int N, M,R[1001], a,b;
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%d %d", &N,&M);
    for(int i=0; i<M; i++){
        scanf("%d %d",&a,&b);
        R[a]++;R[b]++;
    }
    for (int i=1; i<=N; i++){
        printf("%d\n",R[i]);
    }
}
