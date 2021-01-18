#include <stdio.h>

int N, M, r, c, d, ans;
int map[51][51];
int visit[51][51];
int nx, ny, nd;
int dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 };
int step;


int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int nd = 0;
	if (d == 0) nd = 0;
	else if (d == 1) nd = 3;
	else if (d == 2) nd = 2;
	else if (d == 3) nd = 1;
	d = nd;
	int y = r + 1, x = c + 1;
	if (map[y][x] == 0) {
		visit[y][x] = ++step;
	}
	while (1) {
		int orgdir = d;
		int chk = 0;
		for (int i = d + 1; i <= d + 4; i++) {
			nd = i % 4;
			ny = y + dy[nd];
			nx = x + dx[nd];
			if (map[ny][nx] == 0 && visit[ny][nx] == 0) {
				y = ny; x = nx; d = nd;
				visit[ny][nx] = ++step;
				break;
			} else  if (ny<1 || ny> N || nx<1 || nx>M || map[ny][nx] == 1 || visit[ny][nx] != 0) {
				chk++;
			}			
		}
		if (chk == 4) {
			ny = y - dy[orgdir];
			nx = x - dx[orgdir];
			y = ny; x = nx; d = orgdir;
			if (ny<1 || ny> N || nx<1 || nx>M || map[ny][nx] == 1) break;
		}

	}
	printf("%d\n", step);
}