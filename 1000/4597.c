#include <stdio.h>
char S[33];
int main()
{
    freopen("data.txt", "r", stdin);
    while(1){
        scanf("%s", S);	
        if (S[0]=='#') return 0;
        int cnt=0, i=0;
        for(i=0; S[i]!='\0'&&S[i]!='e'&&S[i]!='o';i++){
            if (S[i]=='1') cnt++;
            printf("%c",S[i]);
        }
        if (S[i]=='e'){
            if (cnt%2==0) printf("0\n");
            else printf("1\n");
        }
        if (S[i]=='o'){
            if (cnt%2==0) printf("1\n");
            else printf("0\n");
        }
    }	
}