/*
1. BFS 방법으로 구현한다.
2. Que를 구현한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct point Point;
typedef struct point {
	int y;
	int x;
};
typedef struct Node *pNode;
typedef struct Node{
	Point p;
	int step;
	pNode next;
};
typedef struct Que *pQue;
typedef struct Que {
	int cnt;
	pNode head;
	pNode tail;
};

void enqueue(struct Que *pQue, Point p, int step) {
	printf("enqu: %d %d %d\n", p.y, p.x, step);
	pNode newNode = (pNode)malloc(sizeof(struct Node));
	newNode->p = p;
	newNode->next = NULL;
	newNode->step = step;
	if (pQue->cnt == 0) {
		pQue->head = pQue->tail = newNode;
	}
	else {
		pQue->tail->next = newNode;
		pQue->tail = newNode;
	}
	pQue->cnt++;
}
void dequeue(struct Que *pQue) {	
	printf("dequ\n");
	if (pQue->cnt == 0) return;
	pNode temp = pQue->head;
	if (pQue->cnt == 1) {
		pQue->head = pQue->tail = NULL;
	}
	else {
		pQue->head = pQue->head->next;
	}
	free(temp);
	pQue->cnt--;
}

int main() {
	int N, M;
	Point P1, P2;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	scanf("%d %d", &(P1.y), &(P1.x));
	scanf("%d %d", &(P2.y), &(P2.x));
	struct Que *mQue = (struct Que*)malloc(sizeof(struct Que));
	mQue->cnt = 0;
	mQue->head = NULL;
	mQue->tail = NULL;
	int visit[101][101] = { 0, };
	int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int y,x, ny, nx;
	int step = 0;
	Point P;
	visit[P1.y][P1.x] = 1;
	enqueue(mQue, P1, step);
	while (mQue->cnt >= 0) {
		Point r_point = mQue->head->p;
		step = mQue->head->step;
		x = r_point.x;
		y = r_point.y;
		printf("[%d][%d] [%d]\n", y, x, step);
		if ((y == P2.y)&&(x == P2.x)) break;
		dequeue(mQue);
		for (int i = 0; i < 8; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (visit[ny][nx] == 0) {
				if ((ny >= 1) && (ny <= N) && (nx >= 1) && (nx <= M)) {
					P.x = nx; P.y = ny;
					visit[ny][nx] = 1;
					enqueue(mQue, P, step + 1);
				}
			}
		}
	}
	printf("%d", mQue->head->step);
}
