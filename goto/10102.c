#include <stdio.h>
int n,a,b;
char s1[16];
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%d", &n);
    scanf("%s",s1);    
    for(int i=0; s1[i]; i++){
        if(s1[i]=='A') a++;
        else b++;
    }
    if(a>b) printf("%c",'A');
    else if (a<b) printf("%c",'B');
    else printf("Tie");
}
