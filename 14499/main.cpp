#include <stdio.h>
int N, M, x, y, k, c;
int h[6], map[20][20];
int nx, ny;
void move(int d) {
	if (d == 1) { ny = y; nx = x + 1; }
	if (d == 2) { ny = y; nx = x - 1; }
	if (d == 3) { ny = y - 1; nx = x; }
	if (d == 4) { ny = y + 1; nx = x; }
	if (ny < 0 || ny >= N || nx < 0 || nx >= M) return;
	y = ny; x = nx;
	int temp = h[5];
	if (d == 1) { h[5] = h[1]; h[1] = h[0]; h[0] = h[2]; h[2] = temp; }
	if (d == 2) { h[5] = h[2]; h[2] = h[0]; h[0] = h[1]; h[1] = temp; }
	if (d == 3) { h[5] = h[3]; h[3] = h[0]; h[0] = h[4]; h[4] = temp; }
	if (d == 4) { h[5] = h[4]; h[4] = h[0]; h[0] = h[3]; h[3] = temp; }
	if (map[y][x] == 0) {
		map[y][x] = h[5];
	}
	else {
		h[5] = map[y][x];
		map[y][x] = 0;
	}
	printf("%d\n", h[0]);
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &k);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < k; i++) {
		scanf("%d", &c);
		move(c);
	}	
	return 0;
}