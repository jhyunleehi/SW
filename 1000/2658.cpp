#include <stdio.h>
int map[12][12];
char str[11];


int main() {	
	freopen("data.txt", "r", stdin);
	for (int i=1; i<=10;i++){
		scanf("%s", str);
		for (int j = 0; j < 10; j++) {
			map[i][j+1] = str[j] - '0';
		}
	}	
	int maxy = 0;
	int maxyline[2][2]; //from-to (y,x1) (y,x2)
	for (int i = 1; i <= 10; i++) {
		bool chk = false;
		int  s = 0, e = 0;
		for (int j = 1; j <= 11; j++) {
			if ((map[i][j] == 1) &&(chk==false)) {
				chk = true;
				s = j;
			}
			if ((map[i][j] == 0) && (chk == true)) {
				chk = false;
				e = j-1; 
			}
		}
		if (maxy < (e - s + 1)) {
			maxy = (e - s + 1);
			maxyline[0][0] = i; //y
			maxyline[0][1] = s;  //x
			maxyline[1][0] =i;
			maxyline[1][1] = e;
		}
	}

	int maxx = 0;
	int maxxline[2][2]; //from-to (y,x1) (y,x2)
	for (int i = 1; i <= 10; i++) {
		bool chk = false;
		int  s = 0, e = 0;
		for (int j = 1; j <= 11; j++) {
			if ((map[j][i] == 1) && (chk == false)) {
				chk = true;
				s = j;
			}
			if ((map[j][i] == 0) && (chk == true)) {
				chk = false;
				e = j - 1;
			}
		}
		if (maxx < (e - s + 1)) {
			maxx = (e - s + 1);
			maxxline[0][0] = s; //y
			maxxline[0][1] = i; //x
			maxxline[1][0] = e; //y
			maxxline[1][1] = i; //x
		}
	}


	int a[2], b[2], c[2];
	if (maxx < maxy) {
		a[0] = maxyline[0][0];
		a[1] = maxyline[0][1];
		b[0] = maxyline[1][0];
		b[1] = maxyline[1][1];
		c[0] = a[0];
		c[1] = (a[1] + b[1]) / 2;
		int s = 0, e = 0;
		bool chk = false;
		for (int i = 1; i <= 10; i++) {
			if ((map[i][c[1]] == 1) && (chk == false)) {
				s = i;
				chk = true;
			}
			if ((map[i][c[1]] == 0) && (chk == true)) {
				e = i - 1;
				chk = false;
			}
		}
		if (s == c[0]) c[0] = e;
		else c[0] = s;
		if ((b[1] - a[1]) % 2 == 1) { printf("0\n"); return 0; }
	}else {
		a[0] = maxxline[0][0];
		a[1] = maxxline[0][1];
		b[0] = maxxline[1][0];
		b[1] = maxxline[1][1];
		c[0] = (a[0] + b[0]) / 2;
		c[1] = a[1];
		int s = 0, e = 0;
		bool chk = false;
		for (int i = 1; i <= 10; i++) {
			if ((map[c[0]][i] == 1)&&(chk==false)) {
				s = i;
				chk = true;
			}
			if ((map[c[0]][i] ==0) && (chk == true)) {
				e = i-1;
				chk = false;
			}
		}
		if (s == c[1]) c[1] = e;
		else c[1] = s;
		if ((b[0] - a[0]) % 2 == 1) { printf("0\n");	return 0; }
	}

	if (maxx < maxy) {
		// <----------->
		int S = 0, E = 0;
		if (c[0] < a[0]) { S = c[0]; E = a[0]; }
		else { S = a[0];  E = c[0]; }
	
		for (int y = S; y <= E; y++) {
			int cnt1 = 0, cnt2 = 0;
			for (int x = c[1]; x<= 10; x++) if (map[y][x] == 1) cnt1++;
			for (int x = c[1]; x>= 1; x--) if (map[y][x] == 1) cnt2++;			
			if ((cnt1 != cnt2) || (cnt1 == 0)) {
				printf("0\n");	return 0;			
			}
		}
	}
	else {
		int S = 0, E = 0;
		if (c[1] < a[1]) { S = c[1]; E = a[1]; }
		else { S = a[1]; E = c[1]; }
		for (int x = S; x <= E; x++) {
			int cnt1 = 0, cnt2 = 0;
			for (int y = c[0]; y <= 10; y++) if (map[y][x] == 1) cnt1++;
			for (int y = c[0]; y >= 1; y--) if (map[y][x] == 1) cnt2++;
			if ((cnt1 != cnt2)|| (cnt1 == 0)) {
				printf("0\n");	return 0;
			}			
		}
	}

	//printf("%d,%d  %d,%d  %d,%d \n", a[0], a[1], b[0], b[1], c[0], c[1]);
	int t0 = 0, t1 = 0;
	if (a[0] > b[0]) {
		t0 = a[0]; t1 = a[1];
		a[0] = b[0]; a[1] = b[1];
		b[0] = t0; b[1] = t1;
	}
	else if ((a[0] == b[0]) && (a[1] > b[1])) {
		t0 = a[0]; t1 = a[1];
		a[0] = b[0]; a[1] = b[1];
		b[0] = t0; b[1] = t1;
	}

	if (a[0] > c[0]) {
		t0 = a[0]; t1 = a[1];
		a[0] = c[0]; a[1] = c[1];
		c[0] = t0; c[1] = t1;
	}
	else if ((a[0] == c[0]) && (a[1] > c[1])) {
		t0 = a[0]; t1 = a[1];
		a[0] = c[0]; a[1] = c[1];
		c[0] = t0; c[1] = t1;
	}

	if (b[0] > c[0]) {
		t0 = b[0]; t1 = b[1];
		b[0] = c[0]; b[1] = c[1];
		c[0] = t0; c[1] = t1;
	}
	else if ((b[0] == c[0]) && (b[1] > c[1])) {
		t0 = b[0]; t1 = b[1];
		b[0] = c[0]; b[1] = c[1];
		c[0] = t0; c[1] = t1;
	}
	printf("%d %d\n%d %d\n%d %d\n", a[0], a[1], b[0], b[1], c[0], c[1]);
	return 0;
} 