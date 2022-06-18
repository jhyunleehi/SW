#include <stdio.h>
int N, D[101],A;

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    int ans=0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A);
        if (D[A]==1) {
            ans++;
        }else{
            D[A]=1;
        }
    }    
    printf("%d\n", ans);
}