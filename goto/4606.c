#include<stdio.h>
char str[1<<10];

int main(){
    freopen("data.txt","r",stdin);
    while(fgets(str,1<<10,stdin)){
        for(int i=0;  str[i] != '\n'; i++)  {
            if (str[i] == '#') break;
            if (str[i] ==' ') printf("%%20");
            else if (str[i]=='!') printf("%%21");
            else if (str[i]=='$')printf("%%24");
            else if (str[i] == '%') printf("%%25");
            else if (str[i] =='(') printf("%%28");
            else if (str[i] ==')')printf("%%29");
            else if (str[i] =='*')printf("%%2a");
            else printf("%c", str[i]);
        }   
        printf("\n");
    }
}