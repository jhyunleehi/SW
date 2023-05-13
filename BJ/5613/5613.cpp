#include <stdio.h>

long long ans;
int n;
char s[9];//100,000,000
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    ans += n;
    for (;;) {
        scanf("%s", s);
        if (s[0] == '=') {
            printf("%lld\n", ans);
            return 0;
        }
        switch (s[0]) {
        case '+':
            scanf("%d", &n);
            ans += n;
            break;
        case '-':
            scanf("%d", &n);
            ans -= n;
            break;
        case '*':
            scanf("%d", &n);
            ans *= n;
            break;
        case '/':
            scanf("%d", &n);
            ans /= n;
           break;        
        }
    }
}
