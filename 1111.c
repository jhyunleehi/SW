#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct node *pnode;
typedef struct node {
	int x, y;
	int lv;
	pnode next;
};

typedef struct queue *pqueue;
typedef struct queue {
	int cnt;
	pnode head;
	pnode tail;
};

//int M[100 + 1][100 + 1] = { 0, };
//int V[100 + 1][100 + 1] = { 0, };
//int C[100 + 1][100 + 1] = { 0x7FFFFFFF, }; // 1:visisted  2:count
int N;
int A, B;

void enqueue(struct queue *pq, int y, int x, int lv) {
	//printf("<-enqueue: %d %d %d \n", y, x, lv);
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->x = x;
	newnode->y = y;
	newnode->lv = lv;
	if (pq->cnt == 0) {
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->cnt++;
}

void dequeue(struct queue *pq, int *y, int *x) {
	//printf("dequeue--> %d %d\n", *y, *x);
	*x = -1;
	*y = -1;
	if (pq->cnt <= 0) return;
	*x = pq->head->x;
	*y = pq->head->y;
	struct node *temp = pq->head;
	if (pq->head == pq->tail)
		pq->head = pq->tail = NULL;
	else
		pq->head = pq->head->next;
	free(temp);
	pq->cnt--;
}

void callbfs(struct queue *pq, int A, int B, int **M, int **C) {
	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };
	int lv = 0;
	int y, x, ny, nx;
	int height = 0;
	*(*(C + A) + B) = 0;
	enqueue(pq, A, B, lv);
	while (pq->cnt >= 1) {
		lv = pq->head->lv;
		dequeue(pq, &y, &x);
		if (y == -1) return;
		//V[y][x] = 1;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((nx >= 1) && (ny >= 1) && (nx <= N) && (ny <= N)) {
				//if (V[ny][nx] == 0) {
				
				//height = M[y][x] - M[ny][nx];
				height = *(*(M + y) + x) - *(*(M + ny) + nx);
				//if ((height > 0) && (C[ny][nx] >= height * height + C[y][x])) {
				if ((height > 0) && (*(*(C + ny) + nx) >= height * height + *(*(C + y) + x))) {
					*(*(C + ny) + nx) = height * height + *(*(C + y) + x);
					//C[ny][nx] = height * height + C[y][x];
					enqueue(pq, ny, nx, lv + 1);
				}
				//if ((height < 0) && (C[ny][nx] >= -1 * height + C[y][x])) {
				if ((height < 0) && (*(*(C + ny) + nx) >= -1 * height + *(*(C + y) + x))) {
					//C[ny][nx] = -1 * height + C[y][x];
					*(*(C + ny) + nx) = -1 * height + *(*(C + y) + x);
					enqueue(pq, ny, nx, lv + 1);
				}
				//if ((height == 0) && (C[ny][nx] >= C[y][x])) {
				if ((height == 0) && (*(*(C + ny) + nx) >= *(*(C + y) + x))) {
					*(*(C + ny) + nx) = *(*(C + y) + x);
					//[ny][nx] = C[y][x];
					enqueue(pq, ny, nx, lv + 1);
				}
			}
			//if (V[ny][nx] == 0) {enqueue(pq, ny, nx, lv + 1);}
		//}
		}
	}
	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("[%d]", *(*(C+i)+j) );
		}
		printf("\n");
	}
	*/
}


int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d %d", &A, &B);
	int **M = (int**)(malloc(sizeof(int*) * N + 1));
	int **V = (int**)(malloc(sizeof(int*) * N + 1));
	int **C = (int**)(malloc(sizeof(int*) * N + 1));
	for (int i = 0; i <= N; i++) *(M + i) = (int*)malloc(sizeof(int)*N + 1);
	for (int i = 0; i <= N; i++) *(V + i) = (int*)malloc(sizeof(int)*N + 1);
	for (int i = 0; i <= N; i++) *(C + i) = (int*)malloc(sizeof(int)*N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", *(M + i) + j );
			*(*(C + i) + j) = 0x7FFFFFFF;
		}
	}

	struct queue *pq = (struct queue*)malloc(sizeof(struct queue));
	pq->cnt = 0;
	pq->head = pq->tail = NULL;
	callbfs(pq, A, B, M, C);
	int max = 0x7FFFFFFF;
	int temp1, temp2;
	for (int i = 1; i <= N; i++) {
		temp1 = *(*(M + 1) + i) * *(*(M + 1) + i);
		temp2 = *(*(C + 1) + i);
		if (max > temp1 + temp2)  max = temp1 + temp2;
	}
	for (int i = 1; i <= N; i++) {
		//if (max > M[N][i] * M[N][i] + C[N][i])  max = M[N][i] * M[N][i] + C[N][i];
		temp1 = *(*(M + N) + i) * *(*(M + N) + i);
		temp2 = *(*(C + N) + i);
		if (max > temp1 + temp2)  max = temp1 + temp2;
	}
	for (int i = 2; i < N; i++) {
		//if (max > M[i][1] * M[i][1] + C[i][1])   max = M[i][1] * M[i][1] + C[i][1];
		temp1 = *(*(M + i) + 1) * *(*(M + i) + 1);
		temp2 = *(*(C + i) + 1);
		if (max > temp1 + temp2)  max = temp1 + temp2;
	}
	for (int i = 2; i < N; i++) {
		//if (max > M[i][N] * M[i][N] + C[i][N])   max = M[i][N] * M[i][N] + C[i][N];
		temp1 = *(*(M + i) + N) *  *(*(M + i) + N);
		temp2 = *(*(C + i) + N);
		if (max > temp1 + temp2)  max = temp1 + temp2;
	}
	printf("%d\n", max);
}
