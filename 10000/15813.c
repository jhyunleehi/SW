#include<stdio.h>
int N,ans;
char S[101];
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %s", &N, &S);
    for (int i=0; S[i]!='\0';i++)  ans+=S[i]-'A'+1;            
    printf("%d\n",ans);
}