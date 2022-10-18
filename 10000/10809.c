#include <stdio.h>
char str[101], c;
int ans[26];
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%s", str);
    for (int i = 0; i < 26; i++)
        ans[i] = -1;
    int i = 0;
    while (c = *(str + i))
    {
        if (ans[c - 'a'] == -1)
        {
            ans[c - 'a'] = i;
        }
        i++;
    }
    for (int i = 0; i < 26; i++)
        printf("%d ", ans[i]);
}