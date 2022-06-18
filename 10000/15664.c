#include <stdio.h>
int N, M, A[9];
int C[9], D[9];
int first = 1;
int use[10], chk[10];
void swap(int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void qsort(int L, int R)
{
    int p = L, q = R, m = A[(L + R) / 2];
    while (p <= q)
    {
        while (A[p] < m)
            p++;
        while (A[q] > m)
            q--;
        if (p <= q)
        {
            swap(p, q);
            p++;
            q--;
        }
    }
    if (p < R)
        qsort(p, R);
    if (L < q)
        qsort(L, q);
}

int cmpans()
{
    for (int i = 1; i <= M; i++)
    {
        if (C[i] != D[i])
            return 1;
    }
    return 0;
}

void printans()
{
    for (int i = 1; i <= M; i++)
    {
        D[i] = C[i];
        printf("%d ", C[i]);
    }
    printf("\n");
}

void ans(int s)
{
    // printf("[%d][%d] ", s,k );
    // printans();
    if (s > M)
    {        
        for (int i = 1; i <= M; i++)
        {            
            printf("%d ", C[i]);
        }
        printf("\n");     
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (A[i - 1] == A[i])  continue;
        if (C[s - 1] > A[i])   continue;
        int x = A[i];
        if (use[x] < chk[x])
        {
            use[x]++;            
            C[s] = A[i];
            ans(s + 1);
            use[x]--;
        }
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
        ++chk[A[i]];
    }
    qsort(1, N);
    int j = 1, i = 1;
    i++;
    ans(1);
}