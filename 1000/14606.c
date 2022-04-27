#include <stdio.h>
int n;
int ans;
void call(int p, int q)
{
    int m = (p + q) / 2;
    ans += m * (q - m);
    if (m > p)  call(1, m);
    if (m+1 < q)  call(1, q - m);
}
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    call(1, n);
    printf("%d\n",ans);
}