#include<stdio.h>
int a;
int main(){
    freopen("date.txt","r",stdin);
    scanf("%d",&a);
    printf("%d",a%21);
}