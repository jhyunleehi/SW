#include <stdio.h>
#include <string.h>
int T,ans,cnt;
char str[1<<10];
int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    cnt=0;
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&T);
    while (T--){
        scanf("%s",str);
        ans =  isPalindrome(str);
        printf("%d %d\n", ans, cnt);
    }
}