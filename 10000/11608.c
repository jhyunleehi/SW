#include<stdio.h>

char str[1<<10];
int  A[26],ans;
void qsort (int L, int R){
    int p=L, q=R, v=A[(L+R)/2];
    while (p<q){
        while(A[p]>v)p++;
        while(A[q]<v)q--;
        if (p<=q){
            int temp=A[p];
            A[p]=A[q]; A[q]=temp;
            p++;q--;
        }
    }
    if (L<q) qsort(L,q);
    if (R>p) qsort(p,R);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%s",str);
    for (int i=0; str[i]!='\0'; i++){
        A[str[i]-'a']++;
    }
    qsort(0,25);
    for (int i=2; i<26; i++){
        ans+=A[i];
    }
    printf("%d",ans);
    return 0;
}