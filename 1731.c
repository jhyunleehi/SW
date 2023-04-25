#include<stdio.h>
int N;
int n[50];
int main (){
    freopen("data.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d", n+i);
    }
  if(n[2]-n[1] == n[1]-n[0])
    printf("%d\n",n[N-1]+n[1]-n[0]);
  else printf("%d\n",n[N-1]*(n[1]/n[0]));
}