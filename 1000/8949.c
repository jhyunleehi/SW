#include<stdio.h>
int n1,n2;
int ans[8];
int t1,t2,k;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d",&n1,&n2);
    for (int i=1000000; i>=1; i=i/10){
        t1=n1/i; 
        t2=n2/i;
        ans[k++]=t1+t2;
        n1 = n1%i;
        n2 = n2%i;
    }
    int key=0;
    for (int i=0; i<7; i++ ){
        if (ans[i]>0) key=1;
        if (key) printf("[%d]",ans[i]);        
    }
    printf("\n");
}