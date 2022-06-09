#include <stdio.h>
int N, M;
int a[100001*4], ctree[100001*4];
int init(int p, int q, int node) {
	if (p == q) return ctree[node] = a[p];
	int mid = (p + q) / 2;
	return ctree[node] = init(p, mid, node * 2) + init(mid + 1, q, node * 2 + 1);
}
int gtree(int p, int q, int node, int L, int R) {
	if (R < p || q < L  ) return 0;
	if (L <= p && q <= R) return ctree[node];
	int mid = (p + q) / 2;
	return gtree(p, mid, node * 2, L, R) + gtree(mid + 1, q, node * 2 + 1, L, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d",&N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	int sum = init(1,N,1);	
	for (int k = 1; k <= M; k++) {
		int i = 0, j = 0;
		scanf("%d %d", &i, &j);
		int out = gtree(1, N, 1, i,j);
		printf("%d\n", out);
	}
	return 0;
}