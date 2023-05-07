#include<stdio.h>
int t,p;
double pps;
double ans;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d", &t,&p);    
    int pb=0;
    if (p>=20) {        
        pps=(100-p)/t*1.0;
        ans+=(p-20)/pps;
        ans+=20/(pps/2);
    }else {
        int usep = (20-p);
        pps = (80+(usep*2))/(t*1.0);
        ans = p/(pps/2);        
    }
    printf("%.51f\n",ans);
        
}




