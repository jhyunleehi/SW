#include<stdio.h>
int n,m,k;
int y,x;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    y = k/m;
    x=k%m;
    printf("%d %d\n",y,x);
}