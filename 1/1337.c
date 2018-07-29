/**************************************************************
    Problem: 1337
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N;
    int map[100+1][100+1];
    //freopen("DATA.txt", "r", stdin);
    scanf("%d", &N);    
    int x1=1, x2=N, y1=1, y2=N;
    int num=-1;
    int x = x1, y = y2;
    for (int i = N; i >= 1; i--) for (int j = 1; j <= N; j++) map[i][j] = 0;       
    while (map[y][x] == 0) {
        x = x1, y = y2;
        while( (x<=x2)&&(y>=y1)){     
            map[y--][x++] = (num >= 9)? num = 0: ++num;
        }
        x2--; y2--;
        x = x2; y = y1;
        while ((x>=x1)&&(y==y1)){            
            map[y][x--] = (num >= 9) ? num = 0 : ++num;
        }
        y1++; x2--;
        x = x1; y = y1;
        while((x==x1)&&(y<=y2)){         
            map[y++][x] = (num >= 9) ? num = 0 : ++num;
        }
        x1++;
        y2--;
        x = x1; y = y2;
    }
 
    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= N-i+1; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 1;
}
