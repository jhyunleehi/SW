#include<stdio.h>
int N,a,b,c1,c2;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&N);
    while(N--){
        scanf("%d %d", &a,&b);
        if (a>b) c1++;
        else if(b>a) c2++;
    }
    printf("%d %d\n",c1,c2);
}