#include <stdio.h>
int N, A[500001];
long long ans;
void swap (int a, int b){
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
    ans++;
}
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    for (int i=N-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            if (A[j]>A[j+1]) swap(j, j+1);
        }
    }
    printf ("%lld\n", ans);
}