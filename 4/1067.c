#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct node *pnode;
typedef struct node {
	int val;
	pnode next;
};

typedef struct array *parr;
typedef struct array {
	int cnt;
	pnode head;
	pnode tail;
};

void array_init(struct array *parr, int a, int b) {
	pnode temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->val = a;
	temp1->next = NULL;
	parr->head=parr->tail= temp1;
	parr->cnt = 1;
	pnode temp2 = (struct node*)malloc(sizeof(struct node));
	temp2->val = b;
	temp2->next = NULL;
	parr->head->next = temp2;
	parr->tail = temp2;
	parr->cnt++;
}

void  array_add(struct array *parr, int in) {
	pnode temp = parr->head;
	while (temp->next != NULL ) {
		if (temp->next->val > in) break;
		if(temp->val <in)
			temp = temp->next;
	}
	pnode new_node = (pnode)malloc(sizeof(struct node));
	new_node->val = in;
	new_node->next = temp->next;
	temp->next = new_node;
	parr->cnt++;
}
int main() {
	freopen("data.txt", "r", stdin);
	int Y,X;
	scanf("%d %d", &X , &Y);
	struct array *baseY = (struct array*)malloc(sizeof(struct array));
	struct array *baseX = (struct array*)malloc(sizeof(struct array));
	array_init(baseY, 0, Y);
	array_init(baseX, 0, X);
	int N, a,b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		switch (a) {
		case 0:
			array_add(baseY, b);
			break;
		case 1:
			array_add(baseX, b);
			break;				
		}
	}
	int lenx, leny;
	int max = 0;
	pnode x1 = baseX->head;
	pnode x2 = x1->next;
	while (x2 != NULL) {
		lenx = x2->val - x1->val;
		pnode y1 = baseY->head;
		pnode y2 = y1->next;
		while (y2 != NULL) {
			leny = y2->val - y1->val;
			max = (max < lenx*leny) ? lenx * leny : max;
			//printf("x1:%d x2:%d y1:%d y2:%d max: %d\n", x1->val, x2->val, y1->val, y2->val, max);
			y1 = y1->next;
			y2 = y2->next;
		}
		x1 = x1->next;
		x2 = x2->next;
	}
	printf("%d\n", max);
}
