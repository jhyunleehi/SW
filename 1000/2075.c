#include <stdio.h>
int N,arr[4000],temp;
void qsort(int L, int R){
    int p=L, q=R, v=(arr[(L+R)/2]);
    while (p<q){
        while (arr[p]>v)p++;
        while (arr[q]< v)q--;
        if (p<=q){
            temp=arr[p]; arr[p]=arr[q]; arr[q]=temp;
            p++;q--;
        }
    }
    if (q>L)qsort(L,q);
    if (p<R)qsort(p,R);
}

int main(){
    freopen("data.txt","r",stdin); 
    scanf("%d",&N);
    for (int i=0; i<2*N; i++) arr[i]=0x7FFFFFFF+1;
    
    for (int i=0; i<N; i++){
        for(int j=N; j<2*N; j++){
            scanf("%d",&arr[j]);
        }
        qsort(0,2*N-1);
    }
    printf("%d",arr[N-1]);
}

