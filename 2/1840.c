/**************************************************************
    Problem: 1840
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1264 kb
****************************************************************/
 
 
/*
1. 치즈 내부와 외부를 구분하기 위해서 바깥변에서 외부공기에 해당하는 "0"을 전체 탐색한다.
2. 바깥 공기에 대해서 상변 좌변 우변 하변에서 각각 0으로 되어 있는 값들에 대해서 전체 탐색하여 "0"을 -1로 표시한다.
3. 바깥 공기가 "-1"로 표시되면 내부의 "0"은 바깥 과는 다른 영역으로 식별되게 된다.
4. 그리고 "-1"를 만나는 1에 대해서 "9"표시를 하면서 backtrace 진행한다.
5. "9"표 표시된 영역과 "-1"로 표시한다. 이때 9 갯수를 저장한다.
6. 마지막 단계에서 V의 갯수를 출력한다.
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
int **Map;
int N, M;
int ntime;
int ans;
 
void ocall(int y, int x) {
    //printf("ocall: %d %d \n", y, x);
    int ny, nx;
    int dy[4] = { 0,0,-1,1 };
    int dx[4] = { -1,1,0,0 };
    *(*(Map + y) + x) = -1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if ((nx >= 0) && (nx < M) && (ny >= 0) && (ny < N)) {
            if (*(*(Map + ny) + nx) == 0)
                ocall(ny, nx);
        }
    }
}
 
void findoutside(int Y, int X) {
    //printf("findoutside: %d %d \n", Y, X);    
    for (int y = 0; y < N; y++) if (*(*(Map + y) + 0) == 0) ocall(y, 0);
    for (int y = 0; y < N; y++) if (*(*(Map + y) + M-1) == 0) ocall(y, M-1);
    for (int x = 0; x < M; x++) if (*(*(Map + 0) + x) == 0) ocall(0, x);
    for (int x = 0; x < M; x++) if (*(*(Map + N-1) + x) == 0) ocall(N-1, x);
 
}
 
void findsurface() {
    //printf("find surface \n");
    int dy[4] = { 0,0,-1,1 };
    int dx[4] = { -1,1,0,0 };
    int ny, nx;
    ans = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (*(*(Map + y) + x) == 1) {
                if ((*(*(Map + y) + x - 1) == -1) ||
                    (*(*(Map + y) + x + 1) == -1) ||
                    (*(*(Map + y - 1) + x) == -1) ||
                    (*(*(Map + y + 1) + x) == -1)) {
                    *(*(Map + y) + x) = 9;
                }
            }   
        }
    }
}
 
int changsurface() {
    int count = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (*(*(Map + y) + x) == 9) {
                *(*(Map + y) + x) = 0;
                count++;
            }
            if (*(*(Map + y) + x) == -1) {
                *(*(Map + y) + x) = 0;              
            }
        }
    }
    return count;
}
 
void printMap() {   
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            printf("%2d", *(*(Map + y) + x));
        }
        printf("\n");
    }   
}
 
 
int main() {    
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    Map = (int**)malloc(sizeof(int*)*N + 1);
    for(int i=0; i<N; i++)
        *(Map + i) = (int*)malloc(sizeof(int)*M + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", *(Map + i) + j);
        }
    }
    int last = 0;
    do {
        findoutside(N, M);
        findsurface();
        //printMap();
        ans = changsurface();
        //printMap();
        if(ans>0)    last = ans;
        else break;
        ntime++;
    } while (ans > 0);
    printf("%d\n%d\n", ntime, last);
     
    return 0;
}
