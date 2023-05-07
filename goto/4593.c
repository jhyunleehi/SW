#include<stdio.h>
char A[21],B[21];

int main(){
    freopen("data.txt","r",stdin);
    while(A[0]!='E'&&B[0]!='E'){
        int a=0,b=0;
        scanf("%s %s",A,B);
        for(int i=0; A[i]!='\0';i++){
            if (A[i]=='R' || B[i]=='R' ){
                if (A[i] =='S') b++;
                if (B[i] =='S') a++;
            }
            if (A[i]=='P' || B[i]=='P'){
                if (A[i] =='R') b++;
                if (B[i] =='R') a++;
            }
            if (A[i]=='S'||A[i]=='S'){
                if (A[i] =='P') b++;
                if (B[i] =='P') a++;
            }          
        }
        printf("P1: %d\n",a);
        printf("P2: %d\n",b);
    }
}