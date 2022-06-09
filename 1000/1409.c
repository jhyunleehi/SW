/**************************************************************
    Problem: 1409
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
/*
1. N개의 벽장에서 1개의 문이 OPEN되었다고 할때 OPEN이 필요한 방향으로 이동한 칸수를 누적 계산하면 된다.
2. 하지만 2개의 문이 있기 때문에 1번문을 움직이거나 2번 문을 움직이는 가능성이 2가지 이다
3. 1번 문과 2번 문이 이동하는 것으로 Backtrace를 적용한다.
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
int N;
int D[2]; //open door
int *M; 
int ans=0x7FFFFFFF;
 
int S; //사용하려는 벽장 순서
void backtrace(int *M,int D1, int D2, int step, int count) {
    //printf("[%d] [%2d]  D1[%d] D2[%d]\n", step, count, D1, D2 );
 
    int dist;
    if (ans < count) return;
    if (step >= S) {
        if (ans > count) 
            ans =count;
        return;
    }   
    dist = ( D1-  *(M + step)  > 0) ? (D1 - *(M + step)) : -1 * (D1 - *(M + step));  
    backtrace(M, *(M + step), D2, step+1, count+dist); //D1 이동한 경우      
    dist = (D2 - *(M + step) > 0) ? (D2 - *(M + step)) : -1 * (D2 - *(M + step));
    backtrace(M, D1, *(M + step), step+1, count + dist); //D2 이동한 경우            
     
}
 
int main() {    
    int D1, D2;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%d %d", &D1,&D2);
    scanf("%d", &S);
 
    M = (int *)malloc(sizeof(int)*S + 1);
    for (int i = 0; i < S; i++) {
        scanf("%d", M + i);
    }
    backtrace(M, D1, D2, 0, 0);
    printf("%d", ans);
    return 0;
}
