#include <stdio.h>
char a[1020], b[1020], c[1020];
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%s", a);
    int len=0;
    for (int i=0; a[i]; i++) len++;
    b[0]='0';
    int i=1; 
    for (int j=0; a[j];j++){b[i++]=a[j]; }
    for (int j=0; j<4; j++) b[i++]='0'; // <<4

    
    for (int i=len+5; i>=0; i--){
        if ((i-5)>=0){
            c[i] = ((a[i-5]-'0')+(b[i]-'0')) + '0';
        }else{
            c[i] = b[i];
        }
    }
    c[len+5]='\0';

    for (int i=len+5; i>=1; i--){
        if (c[i] =='2') {
            c[i] ='0';
            c[i-1] = (c[i-1]-'0' +1)+'0';
        } 
        if (c[i] =='3') {
            c[i] ='1';
            c[i-1] = (c[i-1]-'0' +1)+'0';
        } 
    }    
    int start =0;
    for (int i=0;c[i]; i++){
        if (c[i]=='1') start=1;
        if (start)  printf("%c",c[i]);    
    }
    
}