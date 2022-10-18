#include <stdio.h>
char str[32];
int main(){
    freopen("data.txt", "r",stdin);        
    while(1){
        long long ans=0;
        scanf("%s",str);
        if (str[0]=='0' && str[1]=='\0'){
            return 0;
        }
        int len=0;
        for(;str[len]!='\0';len++);        
        for (int i=len-1, j=1; i>=0; i--,j++){
            int a=str[i]-'0';
            ans+=((1<<j)-1)*a;
        }
        printf("%lld\n",ans);
    }    
}