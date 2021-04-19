#include <stdio.h>
int n[6], sum, avg;
void qsort(int L, int R) {
	
	int p = L, q = R, v = n[(L + R) / 2];
	while (p <= q) {
		while (v > n[p])p++;
		while (v < n[q])q--;
		if (p <= q) {
			int temp = n[p];
			n[p] = n[q]; n[q] = temp;
			p++; q--;
		}
	}
	if (p < R) qsort(p, R);
	if (q > L) qsort(L, q);
}
int main() {
	freopen("data.txt", "r", stdin);
	int i = 5;
	while (i) {
		scanf("%d", &n[i]);
		sum += n[i];
		i--;
	}
	qsort(1, 5);
	printf("%d\n", sum / 5);
	printf("%d\n", n[3]);
	return 0;
}