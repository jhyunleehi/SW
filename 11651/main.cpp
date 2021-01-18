#include<stdio.h>

typedef struct node* pnode;
typedef struct node {
	int x;
	int y;
};

int N;
struct node list[200000];

void qsorty(int L, int R) {
	int p = L; int q = R;
	int v = list[(L + R) / 2].y;
	while (p <= q) {
		while (v > list[p].y) p++;
		while (v < list[q].y) q--;
		if (p <= q) {
			struct node temp = list[p];
			list[p] = list[q];
			list[q] = temp;
			p++; q--;
		}
	}
	if (L < q) qsorty(L, q);
	if (p < R) qsorty(p, R);
}

void qsortx(int L, int R) {
	int p = L; int q = R;
	int v = list[(L + R) / 2].x;
	while (p <= q) {
		while (v > list[p].x) p++;
		while (v < list[q].x) q--;
		if (p <= q) {
			struct node temp = list[p];
			list[p] = list[q];
			list[q] = temp;
			p++; q--;
		}
	}
	if (L < q) qsortx(L, q);
	if (p < R) qsortx(p, R);
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);
	}
	qsorty(1, N);
	int x = list[1].y;
	int s = 1;
	for (int i = 2; i <= N; i++) {
		if (x != list[i].y) {
			if (i - s >= 2)
				qsortx(s, i - 1);
			s = i;
			x = list[i].y;
		}
	}
	qsortx(s, N);

	for (int i = 1; i <= N; i++) {
		printf("%d %d\n", list[i].x, list[i].y);
	}
	return 0;
}
