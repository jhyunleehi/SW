#include<stdio.h>
float a,b,c;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%f", &a);
    while(1){
    scanf("%f", &b);
    if (b==999.0) return 0;
    printf("%.2f\n", b-a);
    a=b;
    }
}