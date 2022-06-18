#include <stdio.h>
int t, n[5];
void qsort(int L, int R) {
	int p = L, q = R, v = n[(L + R) / 2];
	while (p <= q) {
		while (v > n[p]) p++;
		while (v < n[q])q--;
		if (p <= q) {
			int temp = n[p];
			n[p] = n[q]; n[q] = temp;
			p++; q--;
		}
	}
	if (q > L)qsort(L, q);
	if (p < R)qsort(p, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 5; i++) scanf("%d", &n[i]);
		qsort(0, 4);
		if (n[3] - n[1] >= 4)
			printf("KIN\n");
		else
			printf("%d\n", n[1] + n[2] + n[3]);
	}	
	return 0;
}