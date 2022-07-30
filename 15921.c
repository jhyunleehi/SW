#include <stdio.h>
double ans,n;
int s[1<<7],a[1<<7];
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%lf",&n);
    if (n==0) printf("divide by zero\n");
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        s[a[i]]++;        
    }
    for (int i=0; i<n; i++){        
        ans += a[i]*(s[a[i]] /n);        
    }
    printf("%.3f\n", ans);
}
