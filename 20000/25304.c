#include <stdio.h>
int X,N,a,b,sum;
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%d %d",&X,&N);
    while(N--){
        scanf("%d %d",&a,&b);
        sum+=a*b;
    }
    if (sum==X) printf("yes\n");
    else printf("No\n");
}
