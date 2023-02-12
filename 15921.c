#include <stdio.h>
double ans,n,avg,sum,exp;
int s[1<<7],a[1<<7];
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%lf",&n);
    if (n==0) {
        printf("divide by zero\n");
        return 0;
    }
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        s[a[i]]++;
        sum+=a[i];
    }
    avg = sum/n;
    for (int i=0; i< (1<<7); i++){        
        if (s[i]!=0){
            exp += i*(s[i] /n);        
        }
    }
    printf("%.2f\n", avg/exp);
}
