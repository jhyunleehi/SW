#include <stdio.h>
char s1[1<<6],s2[1<<6];
long long a;
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%lld", &a);    
    int i=0;
    for( ;a>0;i++){
        s1[i]= a&1;
        a=a>>1;
    }
    s1[i]='\0';    
    int j=0, start=0;
    for (i--; i>=0; i--) {
        if (s1[i]==1) start=1;
        if (start)  s2[j++] = s1[i]+'0';
    }
    s2[j]='\0';
    printf("%s", s2);
}
