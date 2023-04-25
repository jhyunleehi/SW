/**************************************************************
    Problem: 1056
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#define _CRT_SECURE_NO_WARNINGS
 
#include<stdio.h>
#include<malloc.h>
typedef struct node *pnode;
typedef struct node {
    int item;
    pnode next;
};
 
typedef struct linkedlist *plink;
typedef struct linkedlist {
    int cnt;
    pnode head;
    pnode tail;
};
 
 
void addList(struct linkedlist *plink, int in) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->item = in;
    newnode->next = NULL;
    if (plink->cnt == 0) {
        plink->head = plink->tail = newnode;
        plink->cnt++;
    }
    else {
        plink->tail->next = newnode;
        plink->tail = newnode;
        plink->cnt++;
    }
}
void printLink(struct linkedlist *plink) {
    pnode temp = plink->head;
    while (temp != NULL) {
        printf("%d\n", temp->item);
        temp = temp->next;
    }
}
 
int main() {
    int A, B;
    struct linkedlist *llink = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    llink->cnt = 0;
    llink->head = NULL;
    llink->tail = NULL;  
    //freopen("data.txt", "r", stdin);
    scanf("%d %d", &A, &B);
    int digit;
    for (int i = A; i <= B; i++) {
        digit = i % 10;
        if ((digit% 3 == 0) && (digit % 10 != 0)) {
            addList(llink, i);
        }
    }
    printLink(llink);
    printf("%d\n", llink->cnt);
}
