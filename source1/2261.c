/**************************************************************
    Problem: 2261
    User: jhyunlee
    Language: C++
    Result: Success
    Time:3 ms
    Memory:1224 kb
****************************************************************/
 
 
/*
1. 각각의 코드간에 해밍거리가 되는지 여부를 매번 판단하는 것은 비용이 발생
2. 따라서 각각의 코드간에 미리 해밍거리가 되는지 여부를 그래프 형태로 재구성
3. 생성된 그래프를 이용하여 최소 도달 경로를 역추적하여 제공
*/
#define _CRT_SECURE_NO_WARNINGS
#define false 0
#define true 1
 
#include<stdio.h>
#include<malloc.h>
 
typedef struct Node *pNode;
typedef struct Node {
    int N;
    int cnt;
    pNode next;
};
 
int N, M;
int *List;
int **Map;
int *visit;
 
pNode *pList;
 
bool chkhaming(int a, int b) {
    int k = a ^ b;
    return !(k&(k - 1));
}
 
void pList_add(int x, int y) {
    //printf("pList_add %d %d\n", x, y);
    pNode newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->N = y;
    newNode->next = NULL;
    pNode temp = *(pList + x);
    if (temp == NULL) {
        *(pList + x) = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
 
void pList_print(int x) {
    //printf("pList_print: %d\n", x);
    pNode temp = *(pList + x);
    if (temp == NULL) {
        printf("NULL\n");
        return;
    }
    while (temp->next != NULL) {
        printf("[%d]->", temp->N);
        temp = temp->next;
    }
    printf("[%d]\n", temp->N);
}
 
int enqueue(pNode *head, pNode *rear, int N,int cnt) {
    //printf("enqueue %d %d \n", N, cnt);
    pNode newNode = (pNode)malloc(sizeof(struct Node));
    newNode->N = N;
    newNode->next = NULL;
    newNode->cnt = cnt;
    if (*head == NULL && *rear == NULL) {
        *head = *rear = newNode;
        return 0;
    }
    (*rear)->next = newNode;
    *rear = newNode;
    return 0;
}
int dequeue(pNode *head, pNode *rear) {
    //printf("dequeue\n");
    pNode temp = *head;
    if (*head == NULL) return -1;
    if (*head == *rear) {
        *head = *rear = NULL;
        return 0;
    }
    *head = (*head)->next;
    free(temp);
    return 0;
}
int gethead(pNode *head) {
    if (head == NULL) return NULL;
    return (*head)->N;
}
 
int main() {
    int S, E;
    char str[32];
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    List = (int*)malloc(sizeof(int)*N + 1);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        //printf("%s \n", str);
        int num = 0;
        for (int j = 0; j < M; j++) {
            if (str[j] == '1')
                num += 1 << ((M - j) - 1);
        }
        *(List + i) = num;
        //printf("%d %d \n", i, *(List + i));
    }
    scanf("%d %d", &S, &E);
    S--;
    E--;
 
    pList = (pNode*)malloc(sizeof(pNode)*N + 1);
    for (int i = 0; i < N; i++) *(pList + i) = NULL;
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (chkhaming(*(List + i), *(List + j))) {
                    pList_add(i, j);
                }
            }
        }
    }
    //for (int i = 0; i < N; i++) pList_print(i);            
    visit = (int*)malloc(sizeof(int*)*N + 1);
    for (int i = 0; i < N; i++) *(visit + i) = 0x7FFFFFFF;
    pNode head = NULL;
    pNode rear = NULL;
    int next;
    int cnt = 0;
    bool cycle = false;
    enqueue(&head, &rear, S, 0);    
    *(visit + S) = 0;
    while (head != NULL) {
        next = gethead(&head);
        cnt = head->cnt + 1;     
        if (next == E) {
            cycle = true;
            break;
        }
        dequeue(&head, &rear);
        pNode temp = *(pList + next);
        while (temp->next != NULL) {
            if (*(visit + (temp->N)) >= cnt) {
                *(visit + (temp->N)) = cnt;
                enqueue(&head, &rear, temp->N, cnt);
            }
            temp = temp->next;
        }
        if (*(visit + (temp->N)) >= cnt) {
            *(visit + (temp->N)) = cnt;
            enqueue(&head, &rear, temp->N, cnt);
        }
 
    }
    if (!cycle) {
        printf("-1\n");
        return -1;
    }
     
    /*
    for (int i = 0; i < N; i++) {
        printf("[%d]:%d ", i, *(visit + i));
    }
    printf("\n");
    */
 
 
    int *result = (int*)malloc(sizeof(int)*(cnt + 1));
    int rc = cnt-1;
    pNode temp = *(pList + E);
    int step = *(visit + E);
    *(result + rc) = E;
    rc--;
    while (temp != NULL ) {
        if (*(visit + (temp->N)) == step -1 ) {
            //printf("(%d) ", temp->N);
            *(result + rc) = temp->N;
            rc--;
            temp = *(pList + temp->N);
            step--;
            continue;
        }
        temp=temp->next;
    }
    *(result + rc) = S;
 
    for (int i = 0; i < cnt; i++) {
        *(result + i) = *(result + i) + 1;
        printf("%d ", *(result + i));
    }
}
