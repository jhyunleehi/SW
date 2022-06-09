#include <stdio.h>

typedef struct  En {
	int n,a, b, c;
	long long s;		
};

struct En E[100];
int N;

void swap(int p, int q) {
	struct En t;
	t = E[p];
	E[p] = E[q];
	E[q] = t;
}
void qsort(int L, int R) {
	int p = L, q = R;
	long long m = (E[L].s + E[R].s) / 2;
	while (p <= q) {
		while (E[p].s < m) p++;
		while (E[q].s > m) q--;
		if (p <= q) {
			swap(p, q);
			p++; q--;
		}
	}
	if (L < q) qsort(L, q);
	if (R > p) qsort(p, R);
}

int main() {
	freopen("d.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &E[i].n, &E[i].a, &E[i].b, &E[i].c);
		E[i].s = (E[i].a * E[i].b * E[i].c);
		E[i].s = E[i].s *1000;
		E[i].s += (E[i].a + E[i].b + E[i].c);
		E[i].s = E[i].s *1000;
		E[i].s += E[i].n;
	}
	qsort(0, N-1);
	for (int i = 0; i < 3; i++) {
		printf("%d ", E[i].n);
	}
	printf("\n");
}

