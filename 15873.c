#include <stdio.h>
char s1[1<<10];
int a, b,len;
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%s",s1);
    for (int i=0; s1[i] !='\0';i++) len++;
    if (len==2) {
        a=s1[0]-'0';
        b=s1[1] -'0';
    }else if (len==4){
        a=(s1[0]-'0')*10+(s1[1]-'0');
        b=(s1[2]-'0')*10+(s1[3]-'0');
    }else if (len==3){
        int temp=(s1[0]-'0')*10+(s1[1]-'0');
        if (temp>10) {
            a=(s1[0]-'0');
            b=(s1[1]-'0')*10+(s1[2]-'0');
        }else {
            a=(s1[0]-'0')*10 + (s1[1]-'0');
            b=(s1[2]-'0');
        }
    }    
    printf("%d\n", a+b);
}
