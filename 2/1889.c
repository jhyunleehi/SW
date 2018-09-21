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
 
void backtrace(int r) { 
    if (r > N) {        
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
    scanf("%d", &N);        
    backtrace(1);
    printf("%d\n", ans);
 
    return 0;
}
