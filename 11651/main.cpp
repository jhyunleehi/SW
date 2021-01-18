#include<stdio.h>

typedef struct point* ppoint;
typedef struct point {
	int y, x;
	long long yx;
};

struct point n[100001];
void swap(int p, int q) {
	struct point temp = n[p];
	n[p] = n[q];
	n[q] = temp;
}

void qsort(int L, int R) {
	int p = L, q = R;
	long long v = n[(L + R) / 2].yx;
	while (p <= q) {
		while (n[p].yx < v)p++;
		while (n[q].yx > v)q--;
		if (p <= q) {
			swap(p, q);
			p++; q--;
		}
	}
	if (q > L) qsort(L, q);
	if (p < R)qsort(p, R);
}
int getint() {
	char ch; int res = 0; bool m = false;
	ch = getchar();
	if (ch == '-') m = true;
	else res = ch - '0';
	while ('0' <= (ch = getchar()) && ch <= '9') {
		res = res * 10 + ch - '0';
	}
	return res * (m ? -1 : 1);
}
int N;
int  main(void) {
	//freopen("data.txt", "r", stdin);
	N = getint();
	for (int i = 0; i < N; i++) {
		n[i].x = getint(); n[i].y = getint();
		n[i].yx = n[i].y; n[i].yx = n[i].yx << 20;
		n[i].yx += n[i].x + 100000;
	}
	qsort(0, N - 1);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", n[i].x, n[i].y);
	}
	return 0;
}