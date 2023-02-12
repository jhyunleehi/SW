#include <stdio.h>

int qlen;

int N, K, L, map[101][101], a, b, x, c;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//y,x
int nx = 1, ny = 1, time = 0, d = 0;

typedef struct control {
	int t;
	char c;
};

struct control ctl[101];
int cidx;

int run() {
	while (1) {
		ny = ny + dir[d][0], nx = nx + dir[d][1];
		time++;
		//printf("[%d] [%d][%d] dir[%d] size[%d]\n", time, ny, nx, d, qlen);
		if (ny<1 || ny>N || nx<1 || nx>N) {
			printf("%d\n", time);
			return -1;
		}
		if ( map[ny][nx] >= (time-qlen)) {
			printf("%d\n", time);
			return -1;
		}
		if (map[ny][nx] == -1) map[ny][nx] = time;
		if (map[ny][nx] == -2) { qlen++; map[ny][nx] = time;}
		if (ctl[cidx].t == time) {
			if (ctl[cidx].c == 'L') d = (d + 4 - 1) % 4;
			if (ctl[cidx].c == 'D') d = (d + 4 + 1) % 4;
			cidx++;
		}
	}
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	for (int y = 0; y <= N; y++) for (x = 0; x <= N; x++) map[y][x] = -1;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = -2;
	}
	qlen++;
	map[1][1] = 0;
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &x, &c);
		ctl[i].t = x;
		ctl[i].c = c;
	}
	if (run() == -1) return 0;
	return 0;
}