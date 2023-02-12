#include <stdio.h>
char s1[1<<10];
int h,s;
int main(){    
    freopen("data.txt","r",stdin);
    fgets(s1, 1<<10, stdin);
    for(int i=0; s1[i+2]; i++){
        if (s1[i]==':' && s1[i+1]=='-'&& s1[i+2]==')') h++;
        if (s1[i]==':' && s1[i+1]=='-'&& s1[i+2]=='(') s++;
    }
    if (h==0&& s==0) printf("none");
    else if (h>s) printf("happy");
    else if (h<s) printf("sad");
    else if (h==s) printf("unsure");    
}
