/**************************************************************
    Problem: 1462
    User: jhyunlee
    Language: C++
    Result: Success
    Time:249 ms
    Memory:1092 kb
****************************************************************/
 
 
/*
1. 모든 경로에서 가장 먼 지점을 찾는 것이 목표이다.
2. 모서리에서 BFS 방식으로 찾아 가면 가장 먼곳을 찾을 수 있다.
3. 모서리는 좌우상하 한쪽으로만 연결되어 있는 위치를 모서리로 판단할 수 있다.
4. 그런데 링 구조로 되어 있는 경우라면
5. 결국 모든 위치에서 가장 먼 거리를 찾아야 하는 것인가?
6. 어느 지점에서 BFS로 가장 먼곳으로 판단된 곳을 1차로 찾는다.
7. 1차에 검색에서 가장 먼곳으로 추정된 곳에서 다시 BFS로 역으로 다시 검색하여 실제 가장 먼곳을 2차로 찾는다.
8. 1차 위치와 2차 위치의 거리를 구한다.
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct Pos {
    int y;
    int x;
    int cnt;
};
 
typedef struct Node *pNode;
typedef struct Node {
    int y;
    int x;
    int cnt;
    pNode link;
};
 
int N, M;
char **Map;
char **chk;
 
pNode head = NULL;
pNode tail = NULL;
 
 
void printfMap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            printf("%c ", *(*(chk + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}
 
 
void Qadd(pNode* head, pNode* tail, int y, int x, int cnt) {
    //printf("qadd: %d %d %d\n", y, x, cnt);
    pNode temp = (pNode)malloc(sizeof(struct Node));
    temp->y = y;
    temp->x = x;
    temp->cnt = cnt;
    temp->link = NULL;
    if ((*head == NULL) && (*tail == NULL)) {
        *head = *tail = temp;
        return;
    }
    (*tail)->link = temp;
    *tail = temp;
    // printfMap();
}
 
Pos Qdel(pNode* head, pNode *tail) {
    //printf("qdel: \n");
    Pos pos;
    pNode temp = *head;
    if (*head == NULL) {
        //pos.cnt = 0;
        return pos;
    }
    pos.x = (*head)->x;
    pos.y = (*head)->y;
    pos.cnt = (*head)->cnt;
 
    if (*head == *tail)
        *head = *tail = NULL;
    else
        *head = (*head)->link;
    free(temp);
    return pos;
}
 
Pos BFS(int y, int x) {
    //printf("Call BFS: %d %d \n", y, x);
    int dy[4] = { 0,0,-1,1 };
    int dx[4] = { -1,1,0,0 };
    int ny, nx;
    Pos p;
    Qadd(&head, &tail, y, x, 0);
    while (head != NULL) {
        p = Qdel(&head, &tail);
        *(*(chk + p.y) + p.x) = 1;
        for (int i = 0; i < 4; i++) {
            ny = dy[i] + p.y;
            nx = dx[i] + p.x;
            if ((ny >= 0) && (nx >= 0) && (ny < N) && (nx < M)) {
                if ((*(*(Map + ny) + nx) == 'L') &&(*(*(chk + ny) + nx) ==0)) {
                    Qadd(&head, &tail, ny, nx, p.cnt + 1);
                    *(*(chk + ny) + nx) = 1;
                }
            }
        }
    }
    return p;
}
 
void resetchk() {       
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            *(*(chk + i) + j) = 0;
        }       
    }
}
 
int main() {
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    Map = (char**)malloc(sizeof(char*) * N + 1);
    for (int i = 0; i < N; i++) {
        *(Map + i) = (char*)malloc(sizeof(char)*M + 1);
        scanf("%s", *(Map + i));
    }
 
    chk= (char**)malloc(sizeof(char*) * N + 1);
    for (int i = 0; i < N; i++) {
        *(chk + i) = (char*)malloc(sizeof(char)*M + 1);     
    }
 
    Pos p;  
    int Max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (*(*(Map + i) + j) == 'L') {
                resetchk();
                p = BFS(i, j);
                if (Max < p.cnt) Max = p.cnt;
                //printf("i:[%d]  j:[%d] cnt:[%d]\n", i, j, Max);
            }
        }
    }   
    printf("%d\n", Max);
    //printfMap();
}
