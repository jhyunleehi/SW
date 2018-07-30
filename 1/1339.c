/**************************************************************
    Problem: 1339
    User: jhyunlee
    Language: C++
    Result: Success
    Time:2 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    if (N < 1 || N > 100 || !(N & 1)) {
        printf("INPUT ERROR\n");
        return 0;
    }
    char **map = (char**)malloc(sizeof(char*)*(N + 1));
    for (int i = 0; i <= N; i++) 
        *(map + i) = (char*)malloc(sizeof(char)*(N + 1));
    for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) *(*(map + i) + j) = NULL;
    int y1 = N / 2+1;
    int y2 = y1;
    int x = N / 2 + 1;
    int y = x;
    int ch = 'A';
    while (x >= 1) {
        y = y2;
        while (y>=y1) {
            *(*(map + y) + x) = ch;
            if (ch == 'Z') ch = 'A'; else ch++;
            y--;
        }
        y1--; y2++; x--;
    }
     
    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= N; j++)
            if (*(*(map + i) + j) == NULL)
                printf("  ");
            else
                printf("%c ", *(*(map + i) + j));
        printf("\n");
    }
    return 1;
}
