#include<stdio.h>
int T,S;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d",&T,&S);
    if (T<=11) {
        printf("%d\n",280);
    }else if ( T>=12 && T<=16 && S==0) {
        printf("%d\n",320);
    }else if ( T>=12 && T<=16 && S==1) {
        printf("%d\n",280);
    }else {
        printf("%d\n",280);
    }
}