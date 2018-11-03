/**************************************************************
    Problem: 2613
    User: jhyunlee
    Language: C++
    Result: Success
    Time:173 ms
    Memory:20628 kb
****************************************************************/
 
 
/*
1. 트리 형태를 전체 탐색하여 최단 경로를 찾는 문제
2. 전체 트리 구성은 array 형태로 구성
3. 0은 익지 않은 토마토 : 미리 이것의 갯수를 합해서 익은 상태 1로 변하는 갯수와 비교한다.
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct Node *pNode;
typedef struct Node {
    int y;
    int x;
    int cnt;
    pNode next;
};
 
void enqueue(pNode *head, pNode *tail, int y, int x, int cnt) {
    //printf("enq: %d, %d, %d\n", y, x, cnt);
    pNode temp = (pNode)malloc(sizeof(struct Node));
    temp->y = y;
    temp->x = x;
    temp->cnt = cnt;
    temp->next = NULL;
    if (*head == NULL) {
        *head = *tail = temp;
        return;
    }
    (*tail)->next = temp;
    *tail = temp;   
}
 
void dequeue(pNode *head, pNode *tail) {
    //printf("deq:n");
    if (*head == NULL) return;
    if (*head == *tail) {
        *head = *tail = NULL;
        return;
    }
    pNode temp = *head;
    *head=(*head)->next;
    free(temp);
}
 
int N, M;
int **Map;
int t_cnt = 0;
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &M, &N);
    Map = (int**)malloc(sizeof(int*)*(N + 1));
    for (int i = 0; i < N; i++) {
        *(Map+i) = (int*)malloc(sizeof(int)*(M + 1));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", *(Map + i) + j);
            if (*(*(Map + i) + j) == 0) ++t_cnt;
            //printf("[%d]", *(*(Map + i) + j));
        }
        //printf("\n");
    }
    pNode head = NULL;
    pNode tail = NULL;
    int dy[] = { 1,-1,0,0 };
    int dx[] = { 0,0,1,-1 };
    int x, y, nx, ny;
    int cnt;
    int t_change = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (*(*(Map + i) + j) == 1) {
                enqueue(&head, &tail, i, j, 0);
            }
        }
    }
    while (head != NULL) {
        y = head->y;
        x = head->x;
        cnt = head->cnt;     
        dequeue(&head, &tail);
        for (int i = 0; i < 4; i++) {
            ny = dy[i] + y;
            nx = dx[i] + x;
            if ((nx >= 0) && (nx < M) && (ny >= 0) && (ny < N)) {
                if (*(*(Map + ny) + nx) == 0) {
                    *(*(Map + ny) + nx) = 1;
                    t_change++;
                    enqueue(&head, &tail, ny, nx, cnt + 1);
                }
            }
        }
        /*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++){
                printf("%2d ", *(*(Map + i) + j) );
            }
            printf("\n");
        }
        printf("\n");
        */
    }
 
    if (t_cnt == 0) {
        printf("0");
    }
    else if ((t_cnt == t_change)) {
        printf("%d", cnt);
    }else printf("-1");
 
}
