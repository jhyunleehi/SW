#include <stdio.h>

int N, M, T;
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int count = 0;
        scanf("%d %d", &N, &M);
        for (int b = 2; b < N; b++) {
        for (int a = 1; a < b; a++) {
            if ((a * a + b * b + M) % (a * b) == 0) {
                printf("%d %d\n", a, b);
                count++;
            }
        }
        }
        printf("%d\n", count);
    }
}
