/**************************************************************
    Problem: 1082
    User: jhyunlee
    Language: C++
    Result: Success
    Time:3 ms
    Memory:1092 kb
****************************************************************/
 
 
/*
BFS를 이용하여 구현한다.
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
int R,C;
char **M;
typedef struct pos {
    int x;
    int y;
};
typedef struct node *pNode;
typedef struct node {
    int cnt;
    struct pos point;
    pNode next;
};
 
struct pos get_head(pNode *head) {
    if (*head != NULL) 
        return (*head)->point;
}
 
void enqueue(pNode *head, pNode *tail, struct pos pt, int count) {
    //printf("enqueue: %d %d  %d \n", pt.y, pt.x, count);
    pNode newNode = (pNode) malloc(sizeof(struct node));
    newNode->cnt = count;
    newNode->point = pt;
    newNode->next = NULL;
    if (*head == NULL && *tail == NULL) {
        *head = *tail = newNode;        
    }
    (*tail)->next = newNode;
    *tail = newNode;
}
 
int dequeue(pNode *head, pNode *tail) {
    //printf("dequeue:  \n");
    pNode temp = *head;
    if (*head == NULL) return -1;
    if (*head == *tail) {
        *head = *tail = NULL;
        return 0;
    }
    *head = (*head)->next;
    free(temp);
    return 0;
}
 
void fire_remap(char **Map, int Y, int X) {
    //printf("fire_remap\n");
    int vy[] = {0,0 ,-1,1};
    int vx[] = { -1,1,0,0};
    int ny, nx;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if ((*(*(Map + y) + x) == '*')) {
                for (int i = 0; i < 4; i++) {
                    ny = y + vy[i];
                    nx = x + vx[i];
                    if ((ny >= 0) && (ny < Y) && (nx >= 0) && (nx < X)) {
                        if (*(*(Map + ny) + nx) == '.') *(*(Map + ny) + nx) = '+';
                    }
                }
            }
 
        }
    }
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (*(*(Map + y) + x) == '+') {
                *(*(Map + y) + x) = '*';
            }
        }
    }   
    //for (int i = 0; i < R; i++) printf("%s\n", *(M + i));  
}
 
 
void BFS(int sy, int sx) {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    int x, y;
    int nx, ny;
    int cnt = 0;
    int stage = cnt;
    pNode head = NULL;
    pNode tail = NULL;
    struct pos pt;  
    pt.x = sx;
    pt.y = sy;  
    enqueue(&head, &tail, pt, cnt);
    while (head != NULL) {      
        x = head->point.x;
        y = head->point.y;
        cnt = (head->cnt) + 1;
        //printf("[%c] %d %d\n", *(*(M + y) + x), y, x);        
        dequeue(&head, &tail);
        if (stage != cnt) {
            stage = cnt;
            fire_remap(M, R, C);
        }
        for (int i = 0; i < 4; i++) {
            //printf("bfs: %d\n", i);
            ny = y + dy[i];
            nx = x + dx[i];
            if ((ny >= 0) && (ny < R) && (nx >= 0) && (nx < C)) {
                struct pos point;
                if (*(*(M + ny) + nx) == '.') {
                    *(*(M + ny) + nx) = 'v';
                    point.y = ny; point.x = nx;
                    enqueue(&head, &tail, point, cnt);
                }
                if (*(*(M + ny) + nx) == 'D') {
                    printf("%d\n", cnt);
                    return ;
                }
            }
        }
    }
    printf("impossible\n");
}
 
int main() {
    int sx = 0;
    int sy = 0; 
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &R, &C);
    M = (char**)malloc(sizeof(char*)*R + 1);
    for (int i = 0; i < R; i++) {
        *(M + i) = (char*)malloc(sizeof(char)*C + 1);
    }
    char *str = (char*)malloc(sizeof(char)*C + 1);
    for (int r = 0; r < R; r++) {
        scanf("%s", str);       
        for (int c = 0; c < C; c++) {
            if (*(str + c) == 'S') {
                sy = r;
                sx = c;
            }
            *(*(M + r) + c) = *(str + c);
        }
        *(*(M + r) + C) = '\0';     
    }
    BFS(sy, sx);
}
