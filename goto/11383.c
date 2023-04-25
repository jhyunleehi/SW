#include <stdio.h>
//뚊 문제
int N, M, chk;
char  A[10][11];
char  B[10][21];
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++){
        scanf("%s", A[i]);
    }
    for (int i=0; i<N; i++){
        scanf("%s", B[i]);
    }
    chk=1;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (A[i][j] != B[i][j*2] || A[i][j] != B[i][j*2+1]){
              chk=0;
              break;  
            }
        }
        if (chk==0) break;
    }
    if (chk==0) printf("Not Eyfa\n");
    else printf("Eyfa\n");    
}