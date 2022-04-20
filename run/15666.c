#include<stdio.h>
int N,M,A[9];

void swap(int a,int b){
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}

void qsort (int L, int R){
    int p=L,q=R,m=A[(L+R)/2];
    while (p<=q){
        while(A[p]<m) p++;
        while(A[q]>m) q--;
        if (p<=q) {
            swap(p,q);
            p++;q--;
        }
    }
    if (p<R) qsort(p,R);;
    if (L<q) qsort (L,q);
}

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for (int i=1;i<=N; i++){
        scanf("%d", &A[i]);
    }
    qsort(1,N);
    for (int i=1; i<=N; i++) {
        printf("%d", A[i]);
    }
}