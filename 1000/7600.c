#include<stdio.h>

int A[26],ans;
char s[251];
int main(){
    freopen("data.txt","r",stdin);
    while(1){
       fgets(s,1024,stdin);
       if (s[0]=='#') return 0;
        for (int i=0; s[i] !='\0'; i++){
            if (s[i] >= 'a' && s[i] <= 'z' ) A[s[i]-'a']++;
            if (s[i] >= 'A' && s[i] <= 'Z' ) A[s[i]-'A']++;
        }
        for (int i=0;i<26; i++){
            if (A[i] >0 ) ans++;
            A[i]=0;
        }
        printf("%d\n", ans);
        ans=0;
    }   
}