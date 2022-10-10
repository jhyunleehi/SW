#include <stdio.h>
#include <malloc.h>
typedef struct node* pnode;
typedef struct node {
	int y,x, s, b;
	pnode next;
};
int qlen;
pnode qhead = NULL;
pnode qtail = NULL;
int N, M, map[11][11], visit[11][11];// 1 wall, 0 path, -1 visited

void enque(int a, int b, int c, int d) {
	struct node *temp = (pnode)malloc(sizeof(struct node));
	temp->y = a; temp->x = b; temp->s = c; temp->b = d;
	if (qlen <= 0) qhead = qtail = temp;
	else {
		qtail->next = temp;
		qtail = temp;
	}
	qlen++;
}
void dequeue() {
	if (qlen <= 0) return;
	struct node* temp = qhead;
	qhead = qhead->next;
	free(temp);
	qlen--;
}
int arrive, ans=0x7FFFFFFF;
void bfs(int y, int x) {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	visit[y][x] = 1;
	enque(y, x, 1, 0);
	while (qlen > 0) {
		int s, b, nx,ny;
		x = qhead->x; y = qhead->y; s = qhead->s; b = qhead->b;
		if (y == N && x == M) { 
			arrive = 1; ans = (ans>s)?s:ans; 
			//printf("%d\n", ans);
		}
		dequeue();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i]; nx = x + dx[i];
			if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
			if (map[ny][nx] == 0 && (visit[ny][nx]==0|| visit[ny][nx] == 2) && b ==0 ) {
				visit[ny][nx] = 1;
				enque(ny, nx, s + 1, b);
			}
			if (map[ny][nx] == 0 &&visit[ny][nx] == 0 && b == 1) {
				visit[ny][nx] = 2;
				enque(ny, nx, s + 1, b);
			}
			if (map[ny][nx] == 1 && b==0) {
				visit[ny][nx] = 2;
				enque(ny, nx, s + 1, 1);
			}
		}
	}
}


int main() {
	freopen("data.txt", "r", stdin);
	char str[1001];
	scanf("%d %d",&N,&M);
	for (int y = 1; y <= N; y++) {
		scanf("%s", str);
		for (int x = 1; x <= M; x++) {
			map[y][x] = str[x - 1] - '0';
		}
	}
	bfs(1, 1);
	if (arrive) printf("%d\n", ans);
	else printf("-1\n");
	
	return 0;
}