#include <stdio.h>
int IN[1000000 + 1];
int  N[1000000 + 1];
int  M[1000000 + 1];
int n, m;
void qsort(int L, int R) {
	int p = L, q = R, m = N[(L + R) / 2];
	while (p <= q) {
		while (N[p] < m) p++;
		while (N[q] > m)q--;
		if (p <= q) {
			int temp = N[p];
			N[p] = N[q]; N[q] = temp;
			p++; q--;
		}
	}
	if (q > L) qsort(L, q);
	if (p < R)qsort(p, R);
}
void dedup() {
	m = 0;
	N[n] = 0x7FFFFFFF;
	for (int i = 0; i < n ; i++) {
		if (N[i] != N[i+1]) {
			M[m] = N[i];
			m++;
		}
	}
	
}
int bsearch(int L, int R, int num) {
	int  p = L, q = R, mid = (L+R)/2;
	while (p <= q) {
		 mid= (p + q) / 2;
		if (M[mid] == num) { return mid; }
		else {
			if (num < M[mid]) q = mid - 1;
			else p = mid + 1;
		}
	}
	return -1;
}

int out;
int main() {
	freopen("data.txt", "r", stdin);	
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &IN[i]);
		N[i] = IN[i];
	}
	qsort(0,n-1);
	dedup();
	for (int i = 0; i < n; i++) {
		out= bsearch(0,m-1,IN[i]);
		printf("%d ", out);
	}	
	printf("\n");
	return 0;
}