#include <stdio.h>
#define N 10
int n[2][10], a, b;
int main()
{
    freopen("data.txt", "r", stdin);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &n[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (n[0][i] > n[1][i])
            a++;
        else if (n[0][i] < n[1][i])
            b++;
    }
    if (a > b)
        printf("A");
    else if (b > a)
        printf("B");
    else if (a == b)
        printf("D");
}
