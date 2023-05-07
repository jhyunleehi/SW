#include <stdio.h>

int N, M[1001],K[1001],ans;
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)  scanf("%d", &M[i]);
    for (int i = 2; i <= N; ++i) {    
        if (M[i - 1] < M[i])     {
            K[i] = K[i - 1] + (M[i] - M[i - 1]);
        }else {
            K[i] = 0;
        }
        ans = (ans < K[i]) ? K[i] : ans;
    }    
    printf("%d\n", ans);
}
