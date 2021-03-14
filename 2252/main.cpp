#include <stdio.h>
#include<malloc.h>
typedef struct node* pnode;
typedef struct node {
	int t;
	pnode next;
};
pnode llist_head[11], llist_tail[11];
int   llcnt[11];
int N, M, nlist[11], a, b;
void llist_add(int f, int t) {
	struct node* temp = (pnode)malloc(sizeof(struct node));
	temp->t = b;
	temp->next = NULL;
	if (llcnt[f] <= 0) {
		llist_tail[f] = llist_head[f] = temp;
	}
	else {
		llist_tail[f]->next = temp;
		llist_tail[f] = temp;
	}
	llcnt[f]++;
}

pnode qhead, qtail;
int qcnt;
void enque(int n) {
	struct node* temp = (pnode)malloc(sizeof(struct node));
	temp->t = n;
	temp->next = NULL;
	if (qcnt <= 0) {
		qhead = qtail = temp;
	}
	else {
		qtail->next = temp;
		qtail = temp;
	}
	qcnt++;
}
void deque() {
	if (qcnt <= 0)return;
	struct node* temp = qhead;
	if (qhead == qtail) {
		qhead = qtail = NULL;
	}
	else {
		qhead = qhead->next;
	}
	free(temp);
	qcnt--;
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		nlist[b]++;
		llist_add(a, b);
	}
	int cnt = 0;
	while (cnt < N) {
		for (int i = 1; i <= N; i++) {
			if (nlist[i] == 0) {
				enque(i);
				nlist[i] = -1;
			}
		}
		if (qcnt > 0) {
			int temp = qhead->t;
			deque();
			printf("%d\n", temp);
			pnode node = llist_head[temp];
			while (node != NULL) {
				nlist[node->t]--;
				node = node->next;
			}
			cnt++;
		}
	}
	return 0;
}