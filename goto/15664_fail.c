#include <stdio.h>
int N, M, A[9];
int C[9], D[9];
int first = 1;

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

void printans(){
      for (int i = 1; i <= M; i++)
        {
            D[i] = C[i];
            printf("%d ", C[i]);
        }
        printf("\n");
}  


void ans(int s,int k)
{
    //printf("[%d][%d] ", s,k );
    //printans();
    if (s > M)
    {
        if (first == 0 && !cmpans())
        {
            return;
        }
        for (int i = 1; i <= M; i++)
        {
            D[i] = C[i];
            printf("%d ", C[i]);
        }
        printf("\n");
        first = 0;
        return;
    }
    for (int i = k; i <= N; i++)
    {
        if (C[s-1] <= A[i])
        {
            C[s] = A[i];
            ans(s + 1, i+1 );
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
    }
    qsort(1, N);
    int j = 1, i = 1;
    i++;
    ans(1,1);
}