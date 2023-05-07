#include<stdio.h>

#define PI 3.141592
int d1,d2;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d", &d1,&d2);
    printf("%.6f",PI*2*d2 + d1*2);
}