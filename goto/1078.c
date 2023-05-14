/*
1. BFS 탐색한다.
2. Queue를 구현한다. 이미 방문한 곳은 다시 방문하지 않는다.
3. 지도상의 위치에서 상하좌우를 탐색하여 저글링이 있는 곳을 Queue에 등록 한다.
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct Node* pNode;
typedef struct Node {
    int y;
    int x;
    int cnt;
    pNode link; 
};
 
void addq(pNode* front, pNode* rear, int y, int x, int cnt) {
    //printf("addq: %d %d %d\n", y, x, cnt);
    pNode temp = (struct Node*)malloc(sizeof(struct Node));
    temp->y = y;
    temp->x = x;
    temp->cnt = cnt;
    temp->link = NULL;
    if (*rear) (*rear)->link = temp;     
    if (!*front) *front = temp;
    *rear = temp;
}
 
struct Node delq(pNode* front, pNode* rear) {
    //printf("delq\n");
    struct Node element;
    if (*front == NULL) {
        element.link = NULL;
        return  element;
    }
    if (*front == *rear) {
        *rear = NULL;
    }
    element = **front;
    pNode temp = *front;
    *front = temp->link;
    free(temp);
    return element;     
}
 
void printMap(char **Map, int M, int N) {
    printf("-------\n");
    for (int i = 0; i < M; i++) {        
        for (int j = 0; j < N; j++) printf("%d", *(*(Map + i) + j) );        
        printf("\n");
    }
}
 
int main() {
    pNode front=NULL;
    pNode rear=NULL;
    int N, M;   
    int A, B;
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &M); //열x, 행y
    char *str = (char*)malloc(sizeof(char)*N + 1);
    char **Map = (char**)malloc(sizeof(char*)*M + 1);   
    for (int i = 0; i < M; i++) *(Map + i) = (char*)malloc(sizeof(char)*N+1);
    for (int i = 0; i < M; i++) {
        scanf("%s", str);
        for (int j = 0; j < N; j++) {
            *(*(Map + i) + j) = *(str + j) - '0';
        }
    }
    scanf("%d %d", &A, &B); //열x 행 y
 
    //printMap(Map, M, N);
    int max = 0;
    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};
    int ny, nx,cnt=0;
    pNode nNode= (pNode)malloc(sizeof(struct Node));
    addq(&front, &rear, B-1, A-1, 3);   
    while (front) {
        *nNode = delq(&front, &rear);
        A = nNode->x;
        B = nNode->y;        
        cnt = nNode->cnt;
        *(*(Map + B) + A) = cnt;
        for (int i = 0; i < 4; i++) {
            ny = dy[i] + B;
            nx = dx[i] + A;
            if ((ny >= 0) && (ny < M) && (nx >= 0) && (nx < N)) {
                if (*(*(Map + ny) + nx) == 1) {
                    addq(&front, &rear, ny, nx, cnt + 1);
                }
            }           
        }       
        if (max < cnt) max = cnt;
    }
    //printMap(Map, M, N);
    printf("%d\n", cnt);
    int ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (*(*(Map + i) + j) == 1) ans++;
        }
    }
    printf("%d\n", ans);
}
