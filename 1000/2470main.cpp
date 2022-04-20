#include <stdio.h>
#include <algorithm>
using namespace std;
int n,N[100001], sum=0x7FFFFFFF, ans[2];
int a,b,temp;
void qsort(int L, int R) {
	int p = L, q = R, v = N[(L + R) / 2];
	while (p <= q) {
		while (N[p] < v) p++;
		while (N[q] > v)q--;
		if (p <= q) {
			int temp = N[p];  N[p] = N[q]; N[q] = temp;
			p++; q--;
		}
	}
	if (q > L) qsort(L, q);
	if (p < R) qsort(p, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d", &N[i]);
	//qsort(1, n);
	sort(N, N+n);
	a = 0, b = n-1;
	while (a < b) {
		temp = ((N[a] + N[b]) < 0) ? (N[a] + N[b]) * -1: (N[a] + N[b]);
		if (temp < sum) {
			sum = temp;
			ans[0] = N[a]; ans[1] = N[b];
		}
		if ((N[a] + N[b]) > 0) 	b--;
		else if ((N[a] + N[b]) < 0) a++;	
		else if ((N[a] + N[b]) == 0) {	a++; b--; }
	}
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}