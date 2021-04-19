#include <stdio.h>
int N, K, M[10];
void qsort(int L, int R) {
	int p = L, q = R, v = M[(L + R) / 2];
	while (p <= q) {
		while (M[p] < v)p++;
		while (M[q] > v)q--;
		if (p <= q) {
			int temp = M[p];
			M[p] = M[q]; M[q] = temp;
			p++; q--;
		}
	}	
	if (L < q) qsort(L, q);
	if (R > p) qsort(p, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d",&N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &M[i]);
	qsort(0, N - 1);
	printf("%d\n", M[K-1]);
	return 0;
}