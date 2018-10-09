/**************************************************************
    Problem: 1824
    User: jhyunlee
    Language: C++
    Result: Success
    Time:18 ms
    Memory:1092 kb
****************************************************************/
 
 
/*
1. 9*9 항목이 모두 0으로 나오는 경우를 생각해야 한다.
2. [1][1] 위치 부터 시작하여 [9]9]까지 현재 위치에서 가질수 있는 최소값을 결정한다.
3. X축 단위에서 {1..9}까지 확인해서 가질수 있는 최소값 확인
4. Y축 단위에서 {1..9}까지 확인해서 가질수 있는 최소값 확인
5. 3*3 단위에서 {1..9}까지 빠진 숫자가 있는지 확인해서 그것을 먼저채워 넣는다
6. O(n3) 복잡도 예상
 
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
int  M[9 + 1][9 + 1];
int  Used[9+1];
int  N = 9;
 
bool chk(int y, int x, int n) {
    //check here
    for (int dx = 1; dx <= N; dx++) {
        if (M[y][dx] == n) {    
            return false;
        }
    }
    for (int dy = 1; dy <= N; dy++) {
        if (M[dy][x] == n) {
            return false;
        }
    }
    int sy = (y - 1) / 3 * 3 + 1;
    int sx = (x - 1) / 3 * 3 + 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (M[sy + i][sx + j] == n) {
                return false;
            }
        }
    }
    return true;
}
 
 
bool recall(int y, int x) {
    //printf("%d %d \n", y, x);
    if (x == N && y == N) return true;
    //call here
    for (int i=1; i <= N; i++) {
        for (int j=1; j <= N; j++) {
            if (M[i][j] == 0) {
                for (int k = 1; k <= N; k++) {                   
                    if ( chk(i, j, k)==true) {
                        M[i][j]=k;
                        if (recall(i, j)) return true;
                        M[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
 
 
int main() {    
    //freopen("data.txt", "r", stdin);
    for (int y = 1; y <= N; y++) 
        for (int x = 1; x <= N; x++)
            scanf("%d", &M[y][x]);
    recall(1, 1);
 
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++)
            printf("%d ", M[y][x]);
        printf("\n");
    }
     
 
 
}
