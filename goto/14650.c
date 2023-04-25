#include <stdio.h>
int N;
int a[3] = {0, 1, 2};
int ans;
void call(int d, int num)
{
    if (d == N)
    {
        if (num % 3 == 0)
        {
            int cnt = 0;
            int temp=num;
            while (temp > 0)
            {
                temp = temp/ 10;
                cnt++;
            }
            if (cnt == N)
            {
                printf("[%d] [%d] \n", d, num);
                ans++;
            }
        }
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (d >= 1 && a[i] == 0 && num == 0)
            continue;
        call(d + 1, num * 10 + a[i]);
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    call(0, 0);
    printf("%d\n", ans);
}