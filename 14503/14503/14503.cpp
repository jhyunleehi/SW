#include <stdio.h>

int N, M, r, c,d,ans;
int map[51][51];
int visit[51][51];
int dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 };

void dfs(int y, int x, int d) {
	ans++;
	visit[y][x] = 1;
	for (int i = d+1; i <= d + 4; i++) {
		int nd = i % 4;
		int ny = y + dy[nd];
		int nx = x + dx[nd];
		if (ny<1 || ny> N || nx<1 || nx>M) continue;
		if (map[ny][nx] == 0 && visit[ny][nx] == 0)
			dfs(ny, nx, nd);
	}
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++){
			scanf("%d", &map[i][j]);
		}
	}
	if (map[r][c] == 0) {
		dfs(r, c, d);
	}
	printf("%d\n", ans);
}