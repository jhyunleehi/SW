#include<stdio.h>
int N;
char s[101];
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++){
        int a=i,b=0;
        while(a>0) {
            b=a%10;
            if (b==M) {
                ans++;                                         
            }
            a=a/10;
        }
    }
    printf("%d\n",ans);
}