#include<stdio.h>
int N,ans,bonus;
char str[10001];

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&N);
    scanf("%s",str);
    for (int i=0; i<N; i++){
        if ( str[i] == 'O'){
            ans+=(i+1);
            ans+=bonus;
            bonus++;
        }else{
            bonus=0;
        }
    }
    printf("%d\n",ans);


}