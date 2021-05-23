#include <stdio.h>
int map[12][12]; //[y][x]
char str[12];
int tsize;

int p[50][2]; //y,x
int np[3][2];

void swap1(int a, int b) {

	if (np[a][1] > np[b][1]) {
		int ty = np[a][0], tx = np[a][1];
		np[a][0] = np[b][0]; np[a][1] = np[b][1];
		np[b][0] = ty; np[b][1] = tx;
	}
}

void swap2(int a, int b) {
	int ty = np[a][0], tx = np[a][1];
	np[a][0] = np[b][0]; np[a][1] = np[b][1];
	np[b][0] = ty; np[b][1] = tx;
}

void output() {
	np[0][0] = p[0][0]; np[0][1] = p[0][1];
	np[1][0] = p[1][0]; np[1][1] = p[1][1];
	np[2][0] = p[2][0]; np[2][1] = p[2][1];

	if (np[0][0] > np[1][0]) swap2(0, 1);
	if (np[0][0] > np[2][0]) swap2(0, 2);
	if (np[1][0] > np[2][0]) swap2(1, 2);

	if (np[0][0] == np[1][0]) swap1(0, 1);
	if (np[0][0] == np[2][0]) swap1(0, 2);
	if (np[1][0] == np[2][0]) swap1(1, 2);
	printf("%d %d\n", np[0][0], np[0][1]);
	printf("%d %d\n", np[1][0], np[1][1]);
	printf("%d %d\n", np[2][0], np[2][1]);
}

bool check1(int y, int x, int z) {
	//printf("check1 [%d][%d][%d]\n", y, x, z);
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	for (int k = 0; k < 4; k++) {
		bool chk = true;
		int ny1 = y + dy[k] * z;
		int nx1 = x + dx[k] * z;
		int ny2 = y + dy[(k + 1) % 4] * z;
		int nx2 = x + dx[(k + 1) % 4] * z;
		if ((ny1 > 10) || (nx1 > 10) || (ny1 < 1) || (nx1 < 1)) continue;
		if ((ny2 > 10) || (nx2 > 10) || (ny2 < 1) || (nx2 < 1)) continue;
		int count = 0;
		if (k == 0) {
			for (int i = y; i >= ny2; i--) {
				for (int j = x; j >= nx1; j--) {
					if (map[i][j] == 1) count++;
					else { chk=false;  break; }
				}
				nx1++;
			}
		}
		if (k == 1) {
			for (int i = y; i >= ny1; i--) {
				for (int j = x; j <= nx2; j++) {
					if (map[i][j] == 1) count++;
					else { chk = false;  break; }
				}
				nx2--;
			}
		}
		if (k == 2) {
			for (int i = y; i <= ny2; i++) {
				for (int j = x; j <= nx1; j++) {
					if (map[i][j] == 1) count++;
					else { chk = false;  break; }
				}
				nx1--;
			}
		}
		if (k == 3) {
			for (int i = y; i <= ny1; i++) {
				for (int j = x; j >= nx2; j--) {
					if (map[i][j] == 1) count++;
					else { chk = false;  break; }
				}
				nx2++;
			}
		}
		if ((count == tsize)&& (chk==true)) {
			p[0][0] = y; p[0][1] = x;
			p[1][0] = y + dy[k] * z; p[1][1] = x + dx[k] * z;;
			p[2][0] = y + dy[(k + 1) % 4] * z; p[2][1] = x + dx[(k + 1) % 4] * z;
			return true;
		}
	}
	return false;
}


bool check2(int y, int x, int z) {
	//printf("check2 [%d][%d][%d]\n", y, x, z);
	int dy[] = { 1,-1,-1,1 };
	int dx[] = { -1, -1,1,1 };
	for (int k = 0; k < 4; k++) {
		bool chk = true;
		int ny1 = y + dy[k] * z;
		int nx1 = x + dx[k] * z;
		int ny2 = y + dy[(k + 1) % 4] * z;
		int nx2 = x + dx[(k + 1) % 4] * z;
		if ((ny1 > 10) || (nx1 > 10) || (ny1 < 1) || (nx1 < 1)) continue;
		if ((ny2 > 10) || (nx2 > 10) || (ny2 < 1) || (nx2 < 1)) continue;
		int count = 0;
		int step = 0;
		if (k == 0) {
			for (int i = x; i >= nx1; i--) {
				for (int j = y - step; j <= y + step; j++) {
					if (map[j][i] == 1) count++;
					else { chk = false;  break; }
				}
				step++;
			}
		}
		if (k == 1) {
			for (int i = y; i >= ny1; i--) {
				for (int j = x-step; j <= x+step; j++) {
					if (map[i][j] == 1) count++;
					else { chk = false;  break; }
				}
				step++;
			}
		}
		if (k == 2) {
			for (int i=x; i<=nx1; i++){
				for (int j= y-step; j<=y+step; j++){
					if (map[j][i] == 1) count++;
					else { chk = false;  break; }
				}
				step++;
			}
		}
		if (k == 3) {
			for (int i = y; i <= ny1; i++) {
				for (int j = x-step; j <= x+step; j++) {
					if (map[i][j] == 1) count++;
					else { chk = false;  break; }
				}
				step++;
			}
		}
		if ((count == tsize) && (chk == true)) {
			p[0][0] = y; p[0][1] = x;
			p[1][0] = y + dy[k] * z; p[1][1] = x + dx[k] * z;;
			p[2][0] = y + dy[(k + 1) % 4] * z; p[2][1] = x + dx[(k + 1) % 4] * z;
			return true;
		}
	}
	return false;
}


int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		scanf("%s", str);
		for (int j = 1; j <= 10; j++) {
			map[i][j] = str[j - 1] - '0';
			if (map[i][j] == 1) tsize++;
		}
	}
	for (int y = 1; y <= 10; y++) {
		for (int x = 1; x <= 10; x++) {
			if (map[y][x] == 1) {
				for (int z = 0; z <= 9; z++) {
					if (check1(y, x, z)) {output();return 0;}
					if (check2(y, x, z)) {	output(); return 0;}
				}

			}
		}
	}
	printf("0\n");
	return 0;
}
