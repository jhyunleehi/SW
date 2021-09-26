#include <stdio.h>
int N, M, B;
int map[501][501];
int wmap[501][501];
int ans = 0x7FFFFFFF, ansh;

int checktime(int wb, int height) {	
	int remove=0, add=0;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (map[n][m] > height) {
				remove += map[n][m] - height;
			}
			else if (map[n][m] < height) {
				add += height - map[n][m];
			}
		}
	}
	if (((wb + remove ) - add) < 0) return -1;
	return remove * 2 + add;
}

int minh=0x7FFFFFFF, maxh;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &B);
	for (int n = 1; n <= N; n++) for (int m = 1; m <= M; m++) {
		scanf("%d", &map[n][m]);
		minh = (minh > map[n][m]) ? map[n][m] : minh;
		maxh = (maxh < map[n][m]) ? map[n][m] : maxh;
	}
	for (int h = 0; h <= 256; h++) {
		int t = checktime(B, h);
		if ((ans >= t) && (t != -1)) {
			ans = t;
			ansh = h;
		}
		//printf("h[%d] ans[%d]\n", h, ans);
	}
	printf("%d %d\n", ans, ansh);
	return 0;
}