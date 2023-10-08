#include <stdio.h>

int N,M;
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int k = 1; k <= N; ++k) {
        scanf("%d", &M);
        for (int i = 1; i <= 100; i++) {           
            if (M < i + (i * i)) {
                printf("%d\n", i - 1);
                break;
            }
        }
    }
}
