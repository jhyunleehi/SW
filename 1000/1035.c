#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

typedef struct Node *pNode;
typedef struct Node {
	int n;
	pNode next;
};

typedef struct queue *pqueue;
typedef struct queue {
	int cnt;
	pNode head;
	pNode tail;
};

void enQueue(struct queue *pqueue, int in) {
	pNode newnode = (struct Node*)malloc(sizeof(struct queue));
	newnode->n = in;
	newnode->next = NULL;
	if (pqueue->cnt == 0) {
		pqueue->head = pqueue->tail = newnode;
		pqueue->cnt++;
	}else{
		pqueue->tail->next = newnode;
		pqueue->tail = newnode;
		pqueue->cnt++;
	}
}

void getmax(struct Node *pNode, int n, int *cnt, int *max) {
	//printf("%d %d %d \n", n, *cnt, *max);
	if (pNode->next == NULL) return;	
	if (pNode->n >= *max) {
		*max = pNode->n;
		*cnt = n;
	}
	getmax(pNode->next, ++n, cnt, max);

}

int main() {
	freopen("data.txt", "r", stdin);
	int N = 10;
	int in;
	pqueue myqueue = (struct queue*)malloc(sizeof(struct queue));
	myqueue->cnt = 0;
	myqueue->head = myqueue->tail = NULL;
	for (int i = 0; i < N; i++) {
		scanf("%d", &in);
		enQueue(myqueue, in);
	}
	int cnt = 1;
	int max = myqueue->head->n;
	getmax(myqueue->head, 1, &cnt, &max);
	printf("%d\n", max);
	printf("%d\n", cnt);
}
