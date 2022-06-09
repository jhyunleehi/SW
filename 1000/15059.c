#include<stdio.h>
int A[3],B[3];
int ans;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d %d", &A[0], &A[1],&A[2]);
    scanf("%d %d %d", &B[0], &B[1],&B[2]);
    for (int i=0; i<3; i++)
    ans+=(B[i]-A[i])>0?(B[i]-A[i]): 0;
    printf("%d\n",ans);
}