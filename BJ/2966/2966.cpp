#include <iostream>
#include<cstdio>

char A1[3][10] = { "ABC","BABC","CCAABB" };
int N;
char S[1 << 7];
int ans[3][2] = { {0,0},{1,0},{2,0}};
char name[3][10] = { "Adrian","Bruno","Goran" };

void qsort(int L, int R) {
    int p = L, q = R, v = (ans[L][1] + ans[R][1]) / 2;
    while (p < q) {
        while (ans[p][1] > v) p++;
        while (ans[q][1] < v) q--;
        if (p <= q) {
            int t1 = ans[p][0], t2 = ans[p][1];
            ans[p][0] = ans[q][0]; ans[p][1] = ans[q][1];
            ans[q][0] = t1; ans[q][1] = t2;
            p++; q--;
        }
    }
    if (q > L) qsort(L, q);
    if (p < R) qsort(p, R);
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%s", &S);
    for (int i = 0, j=0; i < N; ++i, ++j) {
        if (j >= 3) j = 0;
        if (S[i] == A1[0][j]) ans[0][1]++;    
    }    
    for (int i = 0, j = 0; i < N; ++i, ++j) {
        if (j >= 4) j = 0;
        if (S[i] == A1[1][j]) ans[1][1]++;
    }
    for (int i = 0, j = 0; i < N; ++i, ++j) {
        if (j >= 6) j = 0;
        if (S[i] == A1[2][j]) ans[2][1]++;
    }
    qsort(0, 2);

    printf("%d\n", ans[0][1]);    
    if (ans[0][1] == ans[1][1] && ans[1][1] == ans[2][1]) {
        for (int i = 0; i <= 2; i++) printf("%s\n", name[i]);
        return 0;
    }
    if (ans[0][1] == ans[1][1] ) {
        if (ans[0][0] < ans[1][0]) {
            printf("%s\n", name[ans[0][0]]);
            printf("%s\n", name[ans[1][0]]);
        }
        else {
            printf("%s\n", name[ans[1][0]]);
            printf("%s\n", name[ans[0][0]]);
        }
        return 0;
    }
    printf("%s\n", name[ans[0][0]]);    
}

