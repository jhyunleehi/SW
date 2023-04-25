/**************************************************************
    Problem: 1049
    User: jhyunlee
    Language: C++
    Result: Time Limit Exceed
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
 
#include<cstdio>
#include<ctime>
 
int N;
int M[200 + 1][200 + 1];
int Map[200 + 1][200 + 1];
int abs(int x, int y, int p, int q) {
    return ((x - p > 0) ? x - p : p - x) + ((y - q > 0) ? y - q : q - y);
}
 
void chk(int y, int x, int max) {
    int t(0);
    int p(0), q(0), cnt(0);
    for (int i = 1; i <= max; i++) {     
        for (int j = -1*i; j <= i ; j++) { // i ~ -1
            for (int k = -1*i; k<=i; k++){               
                if (((((j < 0) ? j * -1 : j) + ((k < 0) ? k * -1 : k))) == i) {
                    //printf("distance: %d [%d] [%d]\n", i, j, k);
                    p = x + k; q = y + j;
                    if ((p >= 1) && (p <= N) && (q >= 1) && (q <= N)) {
                        if ((M[q][p] != 0)) {
                            if (cnt == 0) {
                                Map[y][x] = M[q][p];
                                cnt++;
                            }
                            else {
                                Map[y][x] = 0;
                                break;
                            }
                        }
                    }
                }
            }
 
        }
        if ((Map[y][x] != 0)) { break; }
    }
     
    for (int i = x; i < (x + p) / 2; i++) {
        for (int j = y; j < (y + q) / 2; j++) {
            Map[j][i] = Map[y][x];
        }
    }
 
}
 
int main() {
    int i(0), j(0);
    //freopen("data.txt", "r", stdin);
    //clock_t t0 = clock();
    scanf("%d", &N);
    for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) scanf("%d", &M[i][j]);
    int y(0), x(0);
    int dy[12] = { 0,-1,0,1, 0,-1,-2,-1,0,1,2,1 };
    int dx[12] = { -1,0,1,0, -2,-1,0,1,2,1,0,-1 };
    int cnt(0);
    int p, q;
    for (y = 1; y <= N; y++) {
        for (x = 1; x <= N; x++) {
            int cnt = 0;
            if (M[y][x] != 0) {
                Map[y][x] = M[y][x];
            }
            else {
                cnt = 0;
                int max = abs(y, x, 1, 1);
                if (max < abs(y, x, N, N)) max = abs(y, x, N, N);
                if (max < abs(y, x, 1, N)) max = abs(y, x, 1, N);
                if (max < abs(y, x, N, 1)) max = abs(y, x, N, 1);
                chk(y, x, max);
            }
        }
    }
     
    for (y = 1; y <= N; y++) {
        for (x = 1; x <= N; x++) {
            printf("%d ", Map[y][x]);
        }
        printf("\n");
    }
     
    //printf("Time: %.3f \n", (clock() - t0) / CLOCKS_PER_SEC);
}
