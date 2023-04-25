#include <stdio.h>
int N,A, x,y,cnt=1;
int M[1001][1001];
int ansy,ansx;

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d", &N,&A);
    x=y=(N+1)/2;    
    M[y][x]=cnt++;
    M[y=y-1][x]=cnt++;
    while(cnt <= N*N){
        if (M[y+1][x] && !M[y][x-1] &&  !M[y-1][x] && !M[y][x+1]) {  //2
            x=x+1;y=y;            
        } else  if (!M[y+1][x] && M[y][x-1] &&  !M[y-1][x] && !M[y][x+1]) { //3
            x=x;y=y+1;
        }else  if (!M[y+1][x] && M[y][x-1] &&  M[y-1][x] && !M[y][x+1]) { //4
            x=x;y=y+1;
        }else if  (!M[y+1][x] && !M[y][x-1] &&  M[y-1][x] && !M[y][x+1]) { // 5
            x=x-1;y=y;
        }else if  (!M[y+1][x] && !M[y][x-1] &&  M[y-1][x] && M[y][x+1]) { //6
            x=x-1;y=y;
        }else if  (!M[y+1][x] && !M[y][x-1] &&  !M[y-1][x] && M[y][x+1]) { //7
            x=x;y=y-1;        
        }else if  (M[y+1][x] && !M[y][x-1] &&  !M[y-1][x] && M[y][x+1]) { //8
            x=x;y=y-1;
        }else if  (M[y+1][x] && !M[y][x-1] &&  !M[y-1][x] && M[y][x+1]) {//9
            x=x-1;y=y;
        }else if (M[y+1][x] && M[y][x-1] &&  !M[y-1][x] && !M[y][x+1]) {  //2
            x=x+1;y=y;            
        }
        M[y][x]=cnt;
        if (cnt==A) {ansy=y; ansx=x; }
        cnt++;
    }
    
    for (int y=1; y<=N; y++){
        for (int x=1; x<=N; x++){
            printf("%d ",M[y][x]);
        }
        printf("\n");
    }
    if (A==1) ansy=ansx=(N+1)/2;   
    if (A==2) {
        ansy=ansx=(N+1)/2;  
        ansy--;        
    }
    printf("%d %d\n", ansy, ansx);
}
