#include<stdio.h>
#include<math.h>
double  A,B;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%lf", &A);
    B=sqrt(A);    
    printf("%.8lf\n",B*4);
}
