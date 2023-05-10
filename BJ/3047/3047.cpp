#include <stdio.h>

int N[3];
char str[4];
void qsort(int L, int R) {
    int p = L, q = R, v = N[(L + R) / 2];
    while (p < q) {
        while (N[p] < v) p++;
        while (N[q] > v) q--;
        if (p <= q) {
            int temp = N[p];
            N[p] = N[q];
            N[q] = temp;
            p++; q--;
        }
    }
    if (q > L) qsort(L, q);
    if (p < R) qsort(p, R);
}
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d %d", &N[0], &N[1], &N[2]);
    scanf("%s", str);
    qsort(0, 2);
    for (int i = 0; i < 3; i++) {
        printf("%d ", N[str[i] - 'A']);
    }    
}
