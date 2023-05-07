#include <stdio.h>
int N,ans;
int a[5];
void call(int n, int step) {
    a[step]=n;
    if (step ==4){
        ans++;
        for (int i=1; i<=4; i++) printf("[%d]", a[i]);
        printf("\n");
        return;
    }
    for (int i=n-1; i>=1; i--){
        call(i, step+1);
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d",&N);
    call(N+1,0);
    printf("%d", ans);
}
