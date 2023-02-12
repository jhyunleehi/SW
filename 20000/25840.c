#include<stdio.h>
int N,k,ans;
int birth[410];
char str[6];
int getday(char * s){
    int m,d;
    m= (*(s)-'0')*10+(*(s+1)-'0');
    d= (*(s+3)-'0')*10+(*(s+4)-'0');
    if (m==02 &&d==29) d=28;
    return m*31+d;
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&N);
    for (int i=0; i<N; i++){
        scanf("%s",str);    
        k=getday(str);
        birth[k]++;
    }
    for (int i=0;i<410;i++){
        if (birth[i] !=0) ans++;
    }
    printf("%d",ans);
    return 0;
}