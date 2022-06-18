#include<stdio.h>
double  a,b,c,ans;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%lf %lf %lf", &a,&b,&c);
    if ((a*b/c)>(a/b*c)){
        printf("%d\n", (int)((a*b/c)) );
    }else {
        printf("%d\n", (int)((a/b*c)) );
    }    
}