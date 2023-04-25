#include<stdio.h>
unsigned long long ans,N;
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%lld",&N);   
    printf("%lld\n",(N-1)*N*(N-1)/2);
}