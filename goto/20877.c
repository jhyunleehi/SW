#include<stdio.h>

int N,a,sum;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&N);
    for(int i=1;i<=N; i++){
        scanf("%d",&a);
        if (a>=7) a=7;
        if (i%2==1)
            sum+=a-2;
        else 
            sum+=a-3;    
    }
    printf("%d\n", sum);
}