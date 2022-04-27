#include <stdio.h>
int T;
int n, a, b;
char str[2];

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d %s", &n, str);
        if (str[0] == 'C')
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%s", str);
                printf("%d ", str[0] - 'A' + 1);
            }
            printf("\n");
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &b);
                printf("%c ", b + 'A' - 1);
            }
            printf("\n");
        }
    }
}