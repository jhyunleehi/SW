#include<stdio.h>
char s[1<<8];
int main(){
    freopen("data.txt","r",stdin);
    scanf("%s",s);
    int ans=0;
    if (s[0]=='0'&&s[1]=='x') {
        for(int i=2; s[i]!='\0'; i++){
            if (s[i]>='a') ans=ans*16+(s[i]-'a')+10;
            else ans = ans*16+s[i]-'0';
        }
        printf("%d\n",ans);
    }else if (s[0]=='0') {
        for(int i=1; s[i]!='\0'; i++){        
            ans = ans*8+s[i]-'0';
        }
        printf("%d\n",ans);
        
    }else {
        printf("%s", s);
    }
}