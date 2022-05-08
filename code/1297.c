#include<stdio.h>
#include<math.h>
double D,H,W;
int h,w;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%lf %lf %lf",&D,&H, &W);
    double DD= D*D;
    double dh = DD*((H*H) /(H*H + W*W));
    double dw = DD*((W*W) /(H*H + W*W));    
    h=(int)sqrt(dh);
    w=(int)sqrt(dw);
    printf("%d %d",h,w);    
}