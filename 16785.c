#include<stdio.h>
int a,b,c;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d %d",&a,&b,&c);
    int d=0;
    while (1){
        if(a * d + b * (d / 7) >= c ) {
            printf("%d",d);
            return 0;
        }
        d++;
    }       
}