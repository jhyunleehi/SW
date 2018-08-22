/**************************************************************
    Problem: 1733
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    const int X = 19;
    const int Y = 19;
    int M[Y+2][X+2] = { 0, };
    //freopen("data.txt", "r", stdin);
    for (int y = 1; y <= Y; y++)
        for (int x = 1; x <= X; x++)
            scanf("%d", &M[y][x]);
    for(int y=1; y<=Y; y++)
        for (int x = 1; x <= X-4; x++) {
            if ((M[y][x] != 0)&&(y<=Y-4)) {
                if (((M[y][x] == M[y][x + 1])&& (M[y][x] == M[y][x + 2]) && (M[y][x] == M[y][x + 3]) && (M[y][x] == M[y][x + 4]) && (M[y][x] != M[y][x + 5]) && (M[y][x] != M[y][x -1])) ||
                    ((M[y][x] == M[y + 1][x])&& (M[y][x] == M[y + 2][x]) && (M[y][x] == M[y + 3][x]) && (M[y][x] == M[y + 4][x]) && (M[y][x] != M[y + 5][x]) && (M[y][x] != M[y -1][x])) ||
                    ((M[y][x] == M[y + 1][x + 1]) && (M[y][x] == M[y + 2][x + 2]) && (M[y][x] == M[y + 3][x + 3]) && (M[y][x] == M[y + 4][x + 4]) && (M[y][x] != M[y + 5][x + 5]) && (M[y][x] != M[y -1][x -1]))) {
                    printf("%d\n%d %d\n", M[y][x], y, x);
                    return 1;
                }
            }
            if ((M[y][x] != 0) && (y >= 5)) {
                if (((M[y][x] == M[y][x + 1]) && (M[y][x] == M[y][x + 2]) && (M[y][x] == M[y][x + 3]) && (M[y][x] == M[y][x + 4]) && (M[y][x] != M[y][x + 5]) && (M[y][x] != M[y][x - 1])) ||
                    (M[y][x] == M[y - 1][x + 1]) && (M[y][x] == M[y - 2][x + 2]) && (M[y][x] == M[y - 3][x + 3]) && (M[y][x] == M[y - 4][x + 4]) && (M[y][x] != M[y - 5][x + 5]) && (M[y][x] != M[y +1][x -1])) {
                    printf("%d\n%d %d\n", M[y][x], y, x);
                    return 1;
                }
            }
        }
    printf("%d\n", 0);
 
    return 1;
}
