#include <stdio.h>
char s[1 << 8];
int main()
{
    freopen("data.txt", "r", stdin);
    while (1)
    {
        int p[26] = {0,};
        int cnt = 0;
        fgets(s, 1 << 8, stdin);
        if (s[0] == '*')
            return 0;
        for (int i = 0; s[i] != '\n'; i++){
            if  (s[i] >= 'a' && s[i] <= 'z'&& 0==p[s[i] - 'a']){
                p[s[i] - 'a']++;
                cnt++;
            }            
        }        
        if (cnt==26)
            printf("Y\n");
        else
            printf("N\n");
    }
}
