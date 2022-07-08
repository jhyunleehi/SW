#include <stdio.h>
int n;
long long m[3];
void swap(long long  *a, long long *b){
    long long temp=*a;
    *a=*b;
    *b=temp;
}
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%d", &n);
    for(int k=1; k<=n; k++){
        scanf("%lld %lld %lld", &m[0], &m[1], &m[2]) ;
        for (int i=0; i<2; i++){
            for (int j=i+1; j<3; j++){
                if (m[i]>m[j]){
                    swap(&m[i], &m[j]);
                }
            }
        }
    printf("Scenario #%d:\n", k);
    if ((m[0]*m[0]+m[1]*m[1]) == m[2]*m[2])    {
        printf("yes\n\n");
    }else{
        printf("no\n\n");
    }   

    }
}