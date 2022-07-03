#include <stdio.h>
typedef struct item {
    char name[21];
    int w;
};
struct item data[101];
int T,N;

void qsort(int L, int R){
    int p=L,q=R,v=data[(L+R)/2].w;
    while(p<q){
        while(v < data[p].w) p++;
        while(v > data[q].w) q--;
        if (p<=q){
            struct item temp = data[p];
            data[p] = data[q];
            data[q] = temp;
            p++; q--;
        }
    }
    if (q>L) qsort(L,q);
    if (p<R) qsort(p,R);
}


int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d",&T);        
    for (int i = T; i; i--){
        scanf("%d", &N);
        for (int j=0; j<N; j++){
            scanf("%s %d", data[j].name,&data[j].w);
        }        
        qsort(0,N-1);
        printf("%s\n",data[0].name);
    }     
}
