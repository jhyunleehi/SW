#include<stdio.h>
int T;
//char str[13000];
char str[13];
int idx=0;
int getint(){
    int temp=0;
    int minus=1;
    while (str[idx] ==' ') idx++;
    if (str[idx]=='-') minus =-1;
    else
    temp=str[idx++]-'0';
    while (str[idx]>='0'&& str[idx]<='9'){
        temp=temp*10+str[idx]-'0';
        idx++;
    }
    return minus*temp;
}
int M[11];
int main(){
    freopen("data.txt","r",stdin);
    idx=0;
    fgets(str,13000,stdin);
    T=getint();
    for (;T>0;T--) {
        fgets(str,13000,stdin);
        idx=0;
        for (int i=0; str[idx]!='\n'; i++){
            M[i]=getint();
        }
    }
}