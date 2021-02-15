#include <stdio.h>
int n,b,X,N[100001],cnt;
void qsort(int L, int R) {
	int p = L, q = R, v = N[(L + R) / 2];
	while (p <= q) {
		while (N[p] < v) p++;
		while (N[q] > v) q--;
		if (p <= q) {
			int temp = N[p]; N[p] = N[q]; N[q] = temp;
			p++; q--;
		}
	}
	if (q > L) qsort(L, q);
	if (p < R)qsort(p, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	for (int i = 1; i<= n; i++) scanf("%d", &N[i]);
	scanf("%d", &X);
	qsort(1, n);
	int a = 1, b = n;	
	while (a < b) {
		if ((N[a] + N[b]) == X) {
			cnt++;
			a++;
		}
		else if ((N[a] + N[b]) < X) {
			a++;
		}else if ((N[a] + N[b]) > X) {
			b--;
		}

	}
	printf("%d\n", cnt);
	return 0;
}