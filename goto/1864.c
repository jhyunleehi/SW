#include <stdio.h>
char in[10];
int main()
{
    freopen("data.txt", "r", stdin);
    while (1)
    {
        scanf("%s", in);
        if (*in == '#')
            break;
        int l = 0, ans = 0, t = 0, p = 1;
        for (l = 0; in[l] != '\0'; l++)
            ;
        for (int k = 0; in[k] != '\0'; k++)
        {
            switch (in[k])
            {
            case '-':
                t = 0;
                break;
            case '\\':
                t = 1;
                break;
            case '(':
                t = 2;
                break;
            case '@':
                t = 3;
                break;
            case '?':
                t = 4;
                break;
            case '>':
                t = 5;
                break;
            case '&':
                t = 6;
                break;
            case '%':
                t = 7;
                break;
            case '/':
                t = -1;
                break;
            }

            int p = 1;
            for (int i = 1; i < l; i++)
                p *= 8;
            if (l > 1)
                ans += p * t;
            else
                ans += t;

            l--;
        }
        printf("%d\n", ans);
    }
    return 0;
}