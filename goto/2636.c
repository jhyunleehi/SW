#include <stdio.h>
#include<malloc.h>
int Y, X;
int map[101][101];
int out[101][101];
int visit[101][101];
typedef struct node* pnode;
typedef struct node {
	int y, x;
	pnode next;
};
typedef struct queue {
	pnode head, tail;
	int len;
};
//

void enqueue(struct queue *q, int y, int x) {
	pnode  temp = (struct node*) malloc(sizeof(struct node));
	temp->y = y; temp->x = x; temp->next = NULL;
	if (q->len == 0) {
		q->head = q->tail = temp;
	}
	else {
		q->tail->next = temp;
		q->tail = temp;
	}
	q->len++;
}
void dequeue(struct queue *q) {
	if ( q->len < 1) return;
	pnode temp = q->head;
	q->head= q->head->next;
	free(temp);
	q->len--;
}
pnode getQueue(struct queue *q) {
	if (q->len < 1) return NULL;
	pnode temp = q->head;
	return temp;
}

void checkOut(struct queue *q) {	
	enqueue(q, 1, 1);
	int dy[4] = { 0,-1,0,1 };
	int dx[4] = { -1,0,1,0 };
	while (q->len > 0) {
		struct node* temp = getQueue(q);
		int y = temp->y;
		int x = temp->x;
		dequeue(q);
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i]; 
			int nx = x + dx[i];
			if (ny<1 || nx <1 || ny >Y || nx>X) continue;
			if (map[ny][nx] == 0 && out[ny][nx] != -1) {
				out[ny][nx] = -1;
				enqueue(q, ny, nx);
			}
		}
	}
}

bool checkAir( int y, int x) {
	int dy[4] = { 0,-1,0,1 };
	int dx[4] = { -1,0,1,0 };	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<1 || nx <1 || ny >Y || nx>X) continue;		
		if (map[ny][nx] == 0 && out[ny][nx] == -1)return true;
	}
	return false;
}


void operation(struct queue* q) {	
	while (q->len > 0) {
		struct node* temp = getQueue(q);
		int y = temp->y;
		int x = temp->x;
		dequeue(q);
		map[y][x] = 0;		
	}
}
int timecnt=1;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &Y, &X);
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			scanf("%d", &map[y][x]);
		}
	}	
	struct queue* q1= (struct queue*)malloc(sizeof(struct queue));
	q1->head = NULL; q1->tail = NULL; q1->len = 0;
	struct queue* q2 = (struct queue*)malloc(sizeof(struct queue));
	q2->head = NULL; q2->tail = NULL; q2->len = 0;
	while(1) {
		for (int y = 0; y <= Y; y++) for (int x = 0; x <= X; x++) out[y][x] = 0;
		checkOut(q1);
		for (int y = 1; y <= Y; y++) {
			for (int x = 1; x <= X; x++) {
				if ((map[y][x] == 1) && checkAir(y, x)) {
					visit[y][x] = timecnt;
					enqueue(q2, y, x);
				}
			}
		}
		if (q2->len == 0) break;
		timecnt++;
		operation(q2);
	} 
	timecnt--;
	printf("%d\n", timecnt);
	int count = 0;
	for (int y = 1; y <= Y; y++) for (int x = 1; x <= X; x++) if (visit[y][x] == timecnt) count++;
	printf("%d\n", count);
	return 0;
}