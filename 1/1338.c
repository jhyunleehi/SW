/**************************************************************
    Problem: 1338
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N;
    int ch = 'A';
    int x, y, x1, x2, y1, y2;
 
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    char **map;
    map = (char**) malloc(sizeof(char*)*(N+1));
    for(int i=0; i<=N; i++) 
        *(map+i) = (char*) malloc(sizeof(char)*(N + 1));
 
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            *(*(map + i) + j) = NULL;
    y = N; x = N;
    x1 = 1; x2 = N;
    y1 = 1; y2 = N; 
    x = x2; y = y2;
    while (y>=1) {       
        while (x >= x1) {
            *(*(map + y) + x) = ch;
            if (ch=='Z') ch = 'A'; else ch++;
            x--; y--;
        }
        y2--; x1++;
        x = x2; y = y2;
    }
 
    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= N; j++)
            if (*(*(map + i) + j) == NULL)
                printf("  ");
            else
                printf("%c ", *(*(map + i) + j) );      
        printf("\n");
    }
 
    return 1;
}
