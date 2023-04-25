#include<stdio.h>

char str[1<<9];
int main(){
    freopen("data.txt","r",stdin);
    while(fgets(str, 1<<9, stdin)){
        int ans=0; 
        for(int i=0; str[i] != '\n';i++){
            if (str[i]=='#') return 0;
            if (str[i]=='\0') break;
            if (str[i] !=' ') {
                ans +=((str[i]-'A')+1)*(i+1);
            }
        }
        printf("%d\n",ans);
    }
}
