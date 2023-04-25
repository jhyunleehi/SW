#include<stdio.h>
char str[1<<8];
int c;
int main(){
    freopen("data.txt","r",stdin);
    while(fgets(str, 1<<8, stdin) ){
        c++;
    }
    printf("%d\n",c);
}