#include <stdio.h>
char str[100001];
char ans[100001];
char temp[100001];
int main()
{
    freopen("data.txt", "r", stdin);
    //fgets(str, 100001, stdin);
    scanf("%[^\n]", str);
    int a = 0, b = 0, t = 0;
    int tag = 0;
    while (1)
    {
        if (*(str + b) == '\n' || *(str + b) == '\0')
        {
            for (int i = t - 1; i >= 0; i--)
            {
                ans[a] = temp[i];
                a++;
            }
            ans[a]='\0';
            t=0;
            break;
        }
        if ( (*(str + b) == ' ') && (!tag))
        {
            for (int i = t - 1; i >= 0; i--)
            {
                ans[a] = temp[i];
                a++;
            }
            ans[a] = str[b];
            a++;
            b++;
            t=0;
            continue;
        }

        if (*(str + b) == '<' )
        {
            tag = 1;
            for (int i = t - 1; i >= 0; i--)
            {
                ans[a] = temp[i];
                a++;
            }
        }
        if (*(str + b) == '>')
        {
            ans[a] = str[b];
            a++;
            b++;
            tag = 0;
            t = 0;
            continue;
        }

        if (tag)
        {
            ans[a] = str[b];
            a++;
            b++;
        }
        else
        {
            temp[t] = str[b];
            t++;
            b++;
        }
    }
    printf("%s\n",ans);
}