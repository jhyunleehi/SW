#include <stdio.h>
int B[7][101],N,num,ans,cnt;
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        cnt = B[num][0];
        B[num][++cnt]=i+1;
        B[num][0]++;
    }
    for (int i=6; i>=1; i--){
        if (B[i][0]==1) {
            ans=i;
            break;
        }
    }
    if (ans==0) printf("none");
    else printf("%d",B[ans][1]);
}