#include<stdio.h>
int A,B,C,D,E,ans;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d %d %d %d", &A,&B,&C,&D,&E);
    if (A<0) {
        ans=(0-A)*C;        
    }
    if (A<=0) {
        ans+=D;
    }
    if (A<=0) {
        ans+=B*E;
    }else{
        ans+=(B-A)*E;
    }
    printf("%d\n",ans);
}
