#include <stdio.h>
#include <math.h>
long long N;
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%lld", &N);    
    printf("%.8f",sqrt((double)N)*4);
}