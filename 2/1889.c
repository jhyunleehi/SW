/**************************************************************
    Problem: 1889
    User: jhyunlee
    Language: C++
    Result: Success
    Time:300 ms
    Memory:1092 kb
****************************************************************/
 
 
#include <stdio.h>
#include<malloc.h>
 
static int N = 0;
static int ans = 0;
static int Q[14 + 2] = { 0, };
static int inc[30], dec[30];
static int visited[14 + 2] = { 0, };
 
bool isPossible( int row, int col ) {
    //printf("(%d %d)\n", row, col );
    if (row == 1) return true;  
    for (int r = 1; r < row; r++) {
        //printf("[%d]", Q[r]);     
        int a = Q[r] - col;
        int b = r - row;
        if (a < 0) a = a * -1;
        if (b < 0) b = b * -1;
        if (a==b) return false;     
    }
    return true;
}
 
void backtrace(int r) {
    //printf("backtrace -- %d\n", row);
    if (r > N) {
        //printf("*********(%d)*[%d]*******\n", ans,N);
        ans++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if(!Q[i]&&!inc[r+i]&&!dec[N+(r-i)+1]){
            Q[i] = inc[r + i] = dec[N + (r - i) + 1] = 1;
            backtrace(r + 1);
            Q[i] = inc[r + i] = dec[N + (r - i) + 1] = 0;
        }
    }   
}
 
 
 
 
int main() {    
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);        
    //for(int i=1; i<=14; i++){
    //  N = i;
    //  ans = 0;
    backtrace(1);
    //    printf("%d , %d\n", i, ans);
    //}
    printf("%d\n", ans);
 
    return 0;
}
