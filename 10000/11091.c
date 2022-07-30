#include <stdio.h>
char s1[1 << 8];
int c[26];
int n;
int getint(char *s){
    int temp=0;
    while(*s>='0' && *s<='9'){
        temp=temp*10+*s-'0';
        s++;
    }
    return temp;
}

int main()
{
    freopen("data.txt", "r", stdin);
    fgets(s1, 1<<8,stdin);
    n=getint(s1);
    while (n--){
        fgets(s1, 1<<8,stdin);
        for (int i = 0; s1[i]; i++){
            if (s1[i] >= 'A' && s1[i] <= 'Z')c[s1[i] - 'A']++;
            if (s1[i] >= 'a' && s1[i] <= 'z')c[s1[i] - 'a']++;
        }
        int pangram = 1;
        for (int i = 0; i < 26; i++){
            if (c[i] == 0){
                pangram = 0;
                break;
            }
        }
        if (pangram){
            printf("pangram\n");
        }
        else{
            printf("missing ");
            for (int i = 0; i < 26; i++){
                if (c[i] == 0)
                    printf("%c", i+'a');
                }
                printf("\n");
        }
        for (int i = 0; i < 26; i++) c[i] = 0;
    }
}
