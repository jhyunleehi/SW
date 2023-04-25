#include<stdio.h>
int N,ans[26];
char str[100];
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&N);
    while(N--){
        scanf("%s",str);
        ans[(*str)-'a']++;
    }
    int find=0;
    for (int i=0; i<26; i++){     
        if (ans[i]>=5){
            printf("%c", i+'a');
            find=1;
        }
    }
    if (find==0)  printf("PREDAJA");    

}