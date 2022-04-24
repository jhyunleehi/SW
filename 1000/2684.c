#include <stdio.h>
char s[41];
int N, A[8];
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    while (N--)
    {
        scanf("%s", s);
        for (int i = 0; i < 40 - 2; i++)
        {
            int t = 0;
            for (int j = 0; j <= 2; j++)
            {
                if (s[i + j] == 'H')
                    t = t << 1 | 1;
                else
                    t = t << 1 | 0;
            }
            A[t]++;
        }
        for (int i = 0; i < 8; i++)
        {
            printf("%d ", A[i]);
            A[i] = 0;
        }
        printf("\n");
    }
}