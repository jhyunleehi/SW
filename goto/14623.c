#include <stdio.h>
char s1[1<<5], s2[1<<5];
long long a,t;
int ans[64];
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%s %s", s1,s2);
    for(int i=0; s1[i]; i++){
        a=a<<1;
        a+=(s1[i]-'0');
    }
    int len=0;
    for(int i=0; s2[i]; i++) len++;
    for ( int i=len-1, j=0; i>=0; i--, j++){
        if (s2[i]=='1') {
            t+=a<<j;
        }
    }
    for (int i=63; i>=0; i--){
        if (t&1==1) ans[i]=1;
        else ans[i] =0;
        t=t>>1;
    }
    int start=0;
    for (int i=0; i<64; i++){
        if (ans[i]==1) start=1;
        if (start) printf("%d", ans[i]);
    }
}
