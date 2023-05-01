#include <stdio.h>
char str[1 << 8];
int count;
int main()
{
    freopen("data.txt", "r", stdin);
    while (1)
    {
        fgets(str, 1 << 8, stdin);
        if (str[0] == '#')
            break;
        count = 0;
        for (int i = 1; str[i] != '\0'; i++)
        {
            if (str[0] == str[i] ||str[0] == str[i]+('a'-'A') )
                count++;
        }
        printf("%c %d\n", str[0], count);
    }
    return 0;
}
