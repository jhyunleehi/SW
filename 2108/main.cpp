#include<stdio.h>

int N,M;
int m[8005];

int get_int() {
	int r=0,m=0, ch = getchar();
	if (ch == '-') m = 1;
	else r = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9') {
		r = r * 10 + ch - '0';
	}
	return r = r * (m  ? -1 : 1);
}

double sum;
int max = 0x7FFFFFFF + 1;
int min = 0x7FFFFFFF;
int num,center,most,second;
int main() {
	freopen("data.txt", "r", stdin);
	N = get_int();
	for (int i = 0; i < N; i++) {
		num = get_int();
		m[num + 4000]++;
		sum += num;
		max = (max < num) ? num: max;
		min = (min > num) ? num : min;
	}
	int cnum = (N + 1) / 2;
	int mostcnt = 0;
	for (int i = 0; i < 8001; i++) 	
		mostcnt = (mostcnt < m[i]) ? m[i] : mostcnt;

	for (int i = 0; i < 8001; i++) {
		if (m[i] == mostcnt) {
			most = i - 4000;
			second++;
		}
		if (second == 2) break;
	}
	
	for (int i = 0; i < 8001; i++) {
		cnum -= m[i];
		if (cnum <= 0) {
			center = i - 4000;
			break;
		}
	}
	printf("%0.0f\n", (sum / N)) ;
	printf("%d\n", center);
	printf("%d\n", most);
	printf("%d\n", max-min);
	
	return 0;
}