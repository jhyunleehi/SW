#include<stdio.h>
char A[21],B[21];

int main(){
    freopen("data.txt","r",stdin);
    while(1){
        int a=0,b=0;
        scanf("%s %s",A,B);
        if ((A[0]=='E') && (B[0]=='E')) 
            return 0;
        for(int i=0; A[i]!='\0';i++){
            if (A[i]=='R' ){                
                if (B[i] =='S') a++;                
                if (B[i] =='P') b++;
            } else if (A[i]=='P' ){                
                if (B[i] =='R') a++;                
                if (B[i] =='S') b++;
            } else if (A[i]=='S'){                
                if (B[i] =='P') a++;                
                if (B[i] =='R') b++;
            } else if (B[i]=='R' ){
                if (A[i] =='S') b++;                
                if (A[i] =='P') a++;                
            } else if  (B[i]=='P'){
                if (A[i] =='R') b++;                
                if (A[i] =='S') a++;                
            }else if (B[i]=='S'){
                if (A[i] =='P') b++;                
                if (A[i] =='R') a++;                
            }    
        }
        printf("P1: %d\n",a);
        printf("P2: %d\n",b);
    }
}