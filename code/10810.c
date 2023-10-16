#include <stdio.h>

int N,M;
int i,j,k;
int A[101];
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d",&N,&M);
    while (M--){
        scanf("%d %d %d", &i,&j,&k);
        for (int n=i;n<=j;n++){
            A[n]=k;
        }
    }
    for (int i=1; i<=N; i++){
        printf("%d ",A[i]);
    }
}