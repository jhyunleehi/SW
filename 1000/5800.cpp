#include <stdio.h>
int T, N, S[51], max;
void qsort(int L, int R) {
	int p = L, q = R, v = S[(L + R) / 2];
	while (p <= q) {
		while (v < S[p])p++;
		while (v > S[q]) q--;
		if (p <= q) {
			int temp = S[p];
			S[p] = S[q]; S[q] = temp;
			p++; q--;
		}
	}
	if (q > L)qsort(L, q);
	if (p < R)qsort(p, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (int k=1; k<=T; k++){
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) scanf("%d", &S[i]);
		qsort(1, N);
		max = 0;
		for (int i = 1; i < N; i++) {
			max = ((S[i] - S[i + 1]) > max) ? (S[i] - S[i + 1]) : max;
		}
		printf("Class %d\n", k);
		printf("Max %d, Min %d, Largest gap %d\n", S[1], S[N], max);
	}	
	return 0;
}