#include<stdio.h>
int N,M;
char s[1<<8];
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&N);
    for(int n=1; n<=N; n++){
        scanf("%d",&M);
        scanf("%s",s);
        for(int i=0; s[i] !='\0';i++){
            if (s[i]=='c') M++;
            if (s[i]=='b') M--;
            if (M==0) break;
        }
        printf("Data Set %d:\n%d\n",n,M);
    }
}