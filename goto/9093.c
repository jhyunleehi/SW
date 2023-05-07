#include<stdio.h>
int n;
char str[1<<10];
int getint(char *s){
    int ans= *s-'0';
    s++;
    while( *s>=0 &&*s<=9){
        ans = ans*10 + *s-'0';
    }
    return ans;
}

int getlen(char *s){
    int i=0;
    while(*(s+i) !='\0' &&*(s+i) != '\n') i++;
    return i;
}

char w[1<<8];
int main(){
    freopen("data.txt","r",stdin);
    fgets(str,1<<10,stdin);
    n=getint(str);
    
    while(fgets(str,1<<10,stdin)){
        int l= getlen(str);
        int k=0;
        for (int i=0; i<=l ;i ++){            
            if (*(str+i) == ' ' ||*(str+i) == '\n'||*(str+i) == '\0' ){
                for (int j=k-1; j>=0; j--){
                    printf("%c", w[j]);
                }
                printf(" ");
                k=0;
                continue;
            }
            w[k++]=*(str+i);
        }
        printf("\n");
    }    
}