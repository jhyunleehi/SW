#include<stdio.h>
unsigned long int a;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%lu",&a);
    printf("%lu\n",a*4);
}