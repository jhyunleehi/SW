#include<stdio.h>
int N,B,cnt;
char num[100];
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d", &N,&B);
    while (N){
        int temp=N%B;
        N=N/B;
        if (temp<10) num[cnt]=temp+'0';
        else if (temp>=10) num[cnt]=(temp-10)+'A';
        cnt++;        
    }
    for (int i=cnt-1; i>=0; i--) {
        printf("%c",num[i]);
    }    
}