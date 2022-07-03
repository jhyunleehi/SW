#include <stdio.h>
int AB[26];
int T,a,b;
char s1[1<<20];
void build(int a,int b){
    int temp=0;
    for (int i=0;i<26; i++){        
        temp = (a*i+b)%26;
        AB[i] =temp;        
    }
}
int main()
{    
    freopen("data.txt","r",stdin);
    scanf("%d", &T) ;
    for (int i = T; i; i--){
        scanf("%d %d",&a,&b);
        scanf("%s",s1);
        build(a,b);
        for (int j=0;s1[j]; j++){            
            s1[j]= (a*(s1[j]-'A')+b)%26 + 'A';
        }
        puts(s1);
    }    
}