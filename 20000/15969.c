#include <stdio.h>
int N, S[1001];
void swap(int p, int q) {
	int temp = S[p];
	S[p] = S[q];
	S[q] = temp;
}
void qsort(int L, int R) {
	int p = L, q = R, m = S[(L + R) / 2];
	while (p <= q) {
		while (S[p] < m)p++;
		while (S[q] > m)q--;
		if (p <= q) {
			swap(p, q);
			p++; q--;
		}
	}
	if (L < q) qsort(L, q);
	if (p < R) qsort(p, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) scanf("%d", &S[i]);
	qsort(1, N);
	printf("%d\n", S[N] - S[1]);
	return 0;
}