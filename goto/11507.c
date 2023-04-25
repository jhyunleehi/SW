#include <stdio.h>
int n[5][14];
char s1[1<<10];

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%s",s1);    
    for (int i = 0; s1[i]; i+=3){
        int p=0;
        int num=0;
        if (s1[i]=='P') p=1;
        else if (s1[i]=='K') p=2;
        else if (s1[i]=='H') p=3;
        else if (s1[i]=='T') p=4;
        num=(s1[i+1]-'0')*10 + (s1[i+2]-'0');
        if (n[p][num] ==0) {
            n[p][num]++;
        }else {
            printf("GRESKA\n");
            return 0;
        }        
    }
    for (int i=1; i<=4;i++){
        int count=0;
        for (int j=1; j<=13;j++){
            if (n[i][j]==0) count++;
        }
        printf("%d ", count);
    }
    printf("\n");
}
