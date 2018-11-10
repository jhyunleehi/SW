/**************************************************************
    Problem: 1003
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
/*
1.linked list를 이용한다.
2.중간 삽입 정렬 방법을 사용한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct Node *pNode;
typedef struct Node {
    int n;
    pNode next;
    pNode prev;
};
typedef struct Que *pQ;
typedef struct Que {
    pNode head;
    pNode tail;
    int count;
};
void print_que(struct Que *pQ) {
    pNode temp = pQ->head;
    for(int i=0; i<pQ->count; i++){
        printf("%d ", temp->n);
        temp = temp->next;
    }   
    printf("\n");
}
void enqueue(struct Que *pQ, int n, int cnt) {
    //printf("enqueue: %d %d\n", n, cnt);
    pNode temp = (pNode)malloc(sizeof(struct Node));
    pNode p;
    int count = cnt;
    temp->n = n;
    temp->next = NULL;
    temp->prev = NULL;
    if (pQ->count <= 0) {     
        pQ->head = pQ->tail = temp;       
    }
    else if (cnt == 0) {        
        p = pQ->tail;
        p->next = temp;
        temp->prev = p;      
        pQ->tail = temp;
    }
    else if (cnt > 0) {
        p = pQ->tail;
        while ((p != pQ->head)&&(count>1)) {
            p = p->prev;
            count--;
        }
        if (p == pQ->head) {
            temp->next = p;
            p->prev = temp;
            pQ->head = temp;
        }
        else {
            p->prev->next = temp;
            temp->prev = p->prev;
            p->prev = temp;
            temp->next = p;
        }
    }
    pQ->count++; 
    //print_que(pQ);
}       
 
 
int main() {
    int N;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    pQ nQ = (pQ)malloc(sizeof(struct Que));
    nQ->head = nQ->tail = NULL;
    nQ->count = 0;
    int S;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &S);
        enqueue(nQ, i, S);
    }
    print_que(nQ);
}
