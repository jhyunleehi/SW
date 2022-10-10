#include <stdio.h>
int N,k,x,sc[1<<10];
void qsort(int L, int R){
    int p=L,q=R,m=sc[(L+R)/2];
    while(p<q){
        while(sc[p] >m)p++;
        while(sc[q]<m)q--;
        if(p<=q){
            int temp=sc[p];
            sc[p]=sc[q];
            sc[q]=temp;
            p++; q--;
        }
    }
    if (q>L)qsort(L,q);
    if (p<R)qsort(p,R);
}
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%d %d",&N,&k);
    for(int i=0; i<N;i++){
        scanf("%d",&sc[i]);
    }
    qsort(0,N-1);
    printf("%d\n",sc[k-1]);
    return 0;
}
