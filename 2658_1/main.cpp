#include <stdio.h>
int map[12][12]; //[y][x]
char str[12];
int p[50][2]; //y,x
int np[3][2];
void pset(int a, int b, int c) {
	np[0][0] = p[a][0];
	np[0][1] = p[a][1];
	np[1][0] = p[b][0];
	np[1][1] = p[b][1];
	np[2][0] = p[c][0];
	np[2][1] = p[c][1];
}
int tricount(int a, int b) {
	int s[2], e[2];
	int count = 0;
	if (np[a][0] < np[b][0]) {
		s[0] = np[a][0];
		e[0] = np[b][0];
	}
	else {
		s[0] = np[b][0];
		e[0] = np[a][0];
	}
	if (np[a][1] < np[b][1]) {
		s[1] = np[a][1];
		e[1] = np[b][1];
	}
	else {
		s[1] = np[b][1];
		e[1] = np[a][1];
	}

	for (int y = s[0]; y <= e[0]; y++) {
		for (int x = s[1]; x <= e[1]; x++) {
			if (map[y][x] == 1) count++;
		}
	}
	return count;
}
void swap(int a, int b) {
	int ty = np[a][0], tx = np[a][1];
	np[a][0] = np[b][0]; np[a][1] = np[b][1];
	np[b][0] = ty; np[b][1] = tx;
}

int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		scanf("%s", str);
		for (int j = 1; j <= 10; j++) {
			map[i][j] = str[j - 1] - '0';
		}
	}
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	int idx = 0;
	int one = 0;
	for (int y = 1; y <= 10; y++) {
		for (int x = 1; x <= 10; x++) {
			if (map[y][x] == 1) {
				int cnt = 0;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (map[ny][nx] == 0)
						cnt++;
				}
				if (cnt >= 3) {
					p[idx][0] = y;
					p[idx][1] = x;
					idx++;
					if (cnt == 4) one++;
				}				
			}
		}
	}
	if (idx == 1) {
		for (int i=0; i<3; i++) printf("%d %d\n", p[0][0], p[0][1]);
		return 0;
	}
	if (idx != 3) {
		printf("0\n");
		return 0;
	}
	if ((idx == 3)&&(one >1)) {
		printf("0\n");
		return 0;
	}
	if (p[0][0] == p[1][0]) pset(0, 1, 2);
	if (p[1][0] == p[2][0]) pset(1, 2, 0);
	if (p[0][0] == p[2][0]) pset(0, 2, 1);
	if (p[0][1] == p[1][1]) pset(0, 1, 2);
	if (p[1][1] == p[2][1]) pset(1, 2, 0);
	if (p[0][1] == p[2][1]) pset(0, 2, 1);
	int zone1 = tricount(0, 2);
	int zone2 = tricount(1, 2);
	if (zone1 == zone2) {
		if (np[0][0] == np[1][0]) swap(0, 1);
		if (np[0][0] == np[2][0]) swap(0, 2);
		if (np[1][0] == np[2][0]) swap(1, 2);
		if (np[0][0] > np[1][0]) swap(0, 1);
		if (np[0][0] > np[2][0]) swap(0, 2);
		if (np[1][0] > np[2][0]) swap(1, 2);
	}
	else {
		printf("0\n");
		return 0;
	}
	printf("%d %d\n", np[0][0], np[0][1]);
	printf("%d %d\n", np[1][0], np[1][1]);
	printf("%d %d\n", np[2][0], np[2][1]);
	return 0;
}
