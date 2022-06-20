#include<stdio.h>
char s1[1<<10],s2[1<<10];
int a1[26],a2[26],cases=1;
int main(){
    freopen("data.txt","r",stdin);
    while(1){
        int same =1 ;
        scanf("%s %s", s1,s2);
        if (s1[0]=='E'&&s1[1]=='N'&&s1[2]=='D') return 0;
        for(int i=0; i<26; i++) a1[i]=0, a2[i]=0;
        for (int i=0; s1[i] !='\0'; i++) a1[s1[i]-'a']++;
        for (int i=0; s2[i] !='\0'; i++) a2[s2[i]-'a']++;
        for (int i=0; i<26; i++){
            if (a1[i] !=a2[i]) {
                printf("Case %d: different\n",cases);
                same=0;
                break;
            }
        }
        if (same) printf("Case %d: same\n",cases);
        cases++;
    }

}