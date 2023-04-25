/**************************************************************
    Problem: 1749
    User: jhyunlee
    Language: C++
    Result: Success
    Time:4 ms
    Memory:2016 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
#define MAX(A,B) (((A)>(B))?(A):(B));
 
int main() {
    int K[3];
    int max_y = 0; 
    int max_x = 0;
    int x[5];
    int y[5];
    int **Map;
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < 3; i++) { 
        scanf("%d", &K[i]); 
    }
    for (int i = 0; i < 5; i++) {
        scanf("%d %d", &y[i], &x[i]);
        max_y = MAX(max_y, y[i]);
        max_x = MAX(max_x, x[i]);
    }
    max_y++; max_x++;
    Map = (int**)malloc(sizeof(int*)*(max_y+1));
    for (int i = 0; i < max_y; i++) {
        *(Map + i) = (int*)malloc(sizeof(int)*(max_x + 1));
    }
    for (int i = 0; i <max_y; i++) {
        for (int j = 0; j <max_x; j++) {
            *(*(Map + i) + j) = 0;
            for (int k = 0; k < 3; k++) {
                if((j-K[k]>=0) && *(*(Map+i)+(j - K[k])) ==0)
                    *(*(Map + i) + j) = 1;
                if ((i - K[k] >= 0) && *(*(Map + (i- K[k])) + j) == 0)
                    *(*(Map + i) + j) = 1;
            }
        }
    }
    /*
    for (int i = 0; i < max_y; i++) {
        for (int j = 0; j < max_x; j++) {
            printf("[%d]", *(*(Map + i) + j));
        }
        printf("\n");
    }   
    */
    for (int i = 0; i < 5; i++) {
        //printf("%d %d\n", y[i], x[i]);
        printf("%c\n", *(*(Map + y[i]) + x[i]) ? ('A') : ('B'));
    }
 
}
