/**************************************************************
    Problem: 1031
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int card[25 + 1][25 + 1] = { 0, };
    int map[25 + 6][25 + 6] = { 0, };
    //freopen("data.txt", "r", stdin);
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &card[i][j]);
        }
    }
    //for (int i = 1; i <= 5; i++) {
    //  for (int j = 1; j <= 5; j++) {
    //      printf("%d ", card[i][j]);
    //  }
    //  printf("\n");
    //}
    int N = 0;
    int cnt = 0;
    for (int k = 1; k <= 25; k++) {
        scanf("%d", &N);
        for (int i = 1; i <= 5; i++) 
            for (int j = 1; j <= 5; j++) 
                if (card[i][j] == N) {
                    map[i][j] = 1;
                }       
        cnt = 0;
        for (int i = 1; i <= 5; i++)
            if ((map[i][1]==1)&& (map[i][2] == 1)&&(map[i][3] == 1) && (map[i][4] == 1) && (map[i][5] == 1)){
                map[i][0] = 1;
                cnt++;
            }
        for (int i = 1; i <= 5; i++)
            if ((map[1][i] == 1) && (map[2][i] == 1) && (map[3][i] == 1) && (map[4][i] == 1) && (map[5][i] == 1)) {
                map[0][i] = 1;
                cnt++;
            }
        if ((map[1][1] == 1) && (map[2][2] == 1) && (map[3][3] == 1) && (map[4][4] == 1) && (map[5][5] == 1)) {
            map[0][0] = 1;
            cnt++;
        }
        if ((map[1][5] == 1) && (map[2][4] == 1) && (map[3][3] == 1) && (map[4][2] == 1) && (map[5][1] == 1)) {
            map[0][0] = 1;
            cnt++;
        }
        if (cnt >= 3) {
            printf("%d", k);
            break;
        }
    }
    return 1;
}
