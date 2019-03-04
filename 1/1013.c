#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
char map[6][12];
char remap[6][12];
int  sum = 0;
void chk_remap_y(int N, int M, int y, int x) {
	int dy, dx;
	int cnt = 0;
	for (int i = -4; i <= 4; i++) {
		dy = y + i;
		dx = x;
		if ((dy >= 1) && (dy >= N)) {
			if (remap[dy][dx] == '*') {
				remap[dy][dx] = '.';
				cnt++;
				if (cnt >= 5) return;
			}
		}
	}
}
void chk_remap_x(int N, int M, int y, int x) {
	int dy, dx;
	int cnt = 0;
	for (int i = -4; i <= 4; i++) {
		dy = y;
		dx = x + i;
		if ((dx >= 1) && (dx >= N)) {
			if (remap[dy][dx] == '*') {
				remap[dy][dx] = '.';
				cnt++;
				if (cnt >= 5) return;
			}
		}
	}
}

void check_bar(int N, int M, int y, int x) {
	int dy, dx;
	int cnt = 0;
	if (remap[y][x] == '*') {
		for (int i = -4; i <= 4; i++) {
			dy = y + i;
			dx = x;
			if ((dy >= 1) && (dy <= N)) {
				if (map[dy][dx] == '*') cnt++;
			}
			if (cnt >= 5) {
				sum++;
				chk_remap_y(N, M, y, x);
				break;
			}
		}
		for (int i = -4; i <= 4; i++) {
			dy = y;
			dx = x + i;
			if ((dx >= 1) && (dx <= N)) {
				if (map[dy][dx] == '*') cnt++;
			}
			if (cnt >= 5) {
				sum++;
				chk_remap_x(N, M, y, x);
				break;
			}
		}


	}
}
int main() {
	int N, M;
	freopen("Text.txt", "r", stdin);
	scanf(" %d %d ", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M + 1; j++) {
			scanf("%c", &map[i][j]);
			remap[i][j] = map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("[%c]%d", map[i][j], j);
		}
		printf("\n");
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check_bar(N, M, i, j);
			printf("%d\n", sum);
		}
	}


}
