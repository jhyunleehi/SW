#include <stdio.h>
int n,s[4],t[4];
int main(){    
    freopen("data.txt","r",stdin);    
    for (int i=0;i<4; i++){
        scanf("%d", &s[i]);
    }
    if ((s[0]==8)||(s[0]==9)) t[0]=1;
    if ((s[3]==8)||(s[3]==9)) t[1]=1;
    if ( s[1]==s[2]) t[2]=1;            
    

    for (int i=0; i<=2; i++){
        if (t[i]==0) {
            printf("answer");
            return 0;
        }
    }
    printf("ignore");        
}
