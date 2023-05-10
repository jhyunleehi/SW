#include <stdio.h>

int R, C, ZR, ZC;
char S[51][51];
char M[255][255];
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d %d %d", &R,&C,&ZR,&ZC);
    for (int i = 0; i < R; i++) {
        scanf("%s", S[i]);
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            for (int y = 0; y < ZR; ++y) {
                for (int x = 0; x < ZC; ++x) {
                    M[r*ZR + y][c*ZC + x] = S[r][c];
                }
            }
        }
    }
    for (int r = 0; r < R*ZR; ++r) {
        for (int c = 0; c < C*ZC; ++c) {
            printf("%c", M[r][c]);
        }
        printf("\n");
    }
}
