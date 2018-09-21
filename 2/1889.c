/**************************************************************
    Problem: 1889
    User: jhyunlee
    Language: C++
    Result: Time Limit Exceed
****************************************************************/
 
 
#include <stdio.h>
#include<malloc.h>
 
static int N = 0;
static int ans = 0;
static int Q[14 + 2] = { 0, };
static int visited[14 + 2] = { 0, };
 
bool isPossible( int row, int col ) {
    //printf("(%d %d)\n", row, col );
    if (row == 1) return true;
    //for (int r = 1; r < row; r++) {
        //printf("[%d]", Q[r]);
        //if (Q[r] == Q[row]) return false;
    //}
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
 
void backtrace(int row) {
    //printf("backtrace -- %d\n", row);
    if (row == N+1) {
        //printf("*********(%d)*[%d]*******\n", ans,N);
        ++ans;
    }
    else {
        for (int col = 1; col <= N; col++) {
            Q[row] = col;
            if (isPossible(row, col) && visited[col]==0) {
                visited[col] = 1;
                backtrace(row + 1);                 
                visited[col] = 0;
            }
            else Q[row] = 0;            
        }
    }
    Q[row] = 0; 
}
 
 
 
 
int main() {    
    scanf("%d", &N);        
    ans = 0;
    backtrace(1);
    printf("%d\n", ans);
}
