#include<stdio.h>
int A,B,N,n,temp;
int ans[1<<5];
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d %d",&A,&B, &N);
    for (int i=0; i<N; i++){
        scanf("%d",&n);    
        temp=temp*A+n;        
    }
    for (int i=0; temp>0; i++){
        ans[i]=temp%B;
        temp=temp/B;
    }
    int start=0;
    for (int i=1<<5; i>=0;i--){
        if (ans[i]!=0) start=1;
        if (start) {
            printf("%d ", ans[i]);
        }
    }
    return 0;
}