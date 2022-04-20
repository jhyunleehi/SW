#include <stdio.h>
#include <malloc.h>
typedef struct node* pnode;
typedef struct node {
	int n;
	pnode next;
};
pnode qhead, qtail;
int  qlen;

void enque(int n) {
	struct node* temp = (pnode)malloc(sizeof(struct node));
	temp->n = n; temp->next = NULL;
	if (qlen == 0) {
		qhead = qtail = temp;
	}
	else {
		qtail->next = temp;
		qtail = temp;
	}
	qlen++;
}

void deque() {
	if (qlen <= 0)return;
	struct node* temp = qhead;
	if (qhead == qtail) {
		qtail = qhead = NULL;
	}
	else {
		qhead = qhead->next;
	}
	free(temp);
	qlen--;
}
int getque() {
	if (qlen <= 0) return -1;
	return qhead->n;
}

int T, N, K, W;
int fromto[1001][1001], tofrom[1001][1001], ref[1001], f, t;
int cost[1001], visit[1001];


void bfs() {
	for (int i = 1; i <= N; i++) {
		if (ref[i] == 0) {
			enque(i);
			visit[i] = cost[i];
		}
	}

	while (qlen) {
		int n = getque();
		int c = cost[n];
		deque();
		for (int i = 1; i <= fromto[n][0]; i++) {
			int v = fromto[n][i];
			ref[v]--;
			if (ref[v] == 0) {
				for (int j = 1; j <= tofrom[v][0]; j++) {
					if (visit[v] < (visit[tofrom[v][j]] + cost[v])) {
						visit[v] = (visit[tofrom[v][j]] + cost[v]);
					}
				}
				enque(v);
			}
		}
	}
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i <= N; i++) {
			cost[i] = visit[i] = -1;
			ref[i] = 0;
			for (int j = 0; j <= N; j++) {
				fromto[i][j] = 0; tofrom[i][j] = 0;
			}
		}
		for (int i = 1; i <= N; i++) scanf("%d", &cost[i]);
		for (int i = 1; i <= K; i++) {
			scanf("%d %d", &f, &t);
			fromto[f][0]++; tofrom[t][0]++;
			fromto[f][fromto[f][0]] = t;
			tofrom[t][tofrom[t][0]] = f;
			ref[t]++;
		}
		scanf("%d", &W);

		qlen = 0; qhead = qtail = NULL;
		bfs();
		printf("%d\n", visit[W]);

	}
}