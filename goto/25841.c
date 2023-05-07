#include<stdio.h>
int a,b,c,ans;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d %d",&a,&b,&c);    
    for (int i=a; i<=b; i++){
        int k=i;
        while(k){
            if (k%10==c) ans++;
            k=k/10;
        }
    }
    printf("%d",ans);
}