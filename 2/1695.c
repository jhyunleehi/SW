/**************************************************************
    Problem: 1695
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
/*
1. N*N 배열에 대해서 기본적으로 순차적으로 검색을 진행한다.
2. 0이 아닌 항목을 만나면 backtrace로 탐색을 한다.
3. 탬색 결과에 따라서 단지수별 배열 갯수를 등록한다.
4. 등록된 배열 항목에 대해서 Quick sort로 정렬하여 순차적으로 출력한다.
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
 
int N;
int count;
int tracecall(char **Map, int y, int x, int cnt) {
    //printf("%d %d %d \n", y, x, cnt);
    *(*(Map + y) + x) = 'v';
    int dy[4] = { 0, 0, -1, 1 };
    int dx[4] = { -1, 1, 0, 0 };
    int ny, nx;
    count = cnt;
    for (int i = 0; i < 4; i++) {
        ny = dy[i] + y;
        nx = dx[i] + x;
        if ((ny >= 0) && (nx >= 0) && (ny < N) && (nx < N)){
            if (*(*(Map + ny) + nx) == '1') {               
                tracecall(Map, ny, nx, ++count);
            }
        }
    }
    return count;
}
 
void qsort(int *M, int L, int R) {
    //printf("sort %d %d \n", L, R);
    int p = L;
    int q = R;
    int v = *(M + (L + R) / 2);
    while (p <= q) {
        while (*(M+p) < v) p++;
        while (*(M+q) > v) q--;
        if (p <= q) {
            int temp = *(M + p);
            *(M + p) = *(M + q);
            *(M + q) = temp;
            p++; q--;
        }
    }
    if (L < q) qsort(M, L, q);
    if (R > p) qsort(M, p, R);
}
 
int main() {
    int ans[250];
    int cnt;
 
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    char str[26];   
    char **Map = (char**)malloc(sizeof(char*)*N);
    for (int i = 0; i < N; i++) {
        *(Map + i) = (char*)malloc(sizeof(char)*N);
    }   
 
 
    for (int i = 0; i < N; i++) {
        scanf("%s", str);       
        for (int j = 0; j < N; j++) {
            *(*(Map + i) + j) = str[j];
        }
    }
         
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (*(*(Map + i) + j) == '1')               
                ans[cnt++] = tracecall(Map, i, j, 1);
        }
    }
 
    qsort(ans, 0, cnt - 1);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) 
        printf("%d\n",ans[i]);
     
     
    return 0;
}
