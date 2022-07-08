#include <stdio.h>
const int div = 1000000007;
int N, M, K;
int in[1 << 3];
long long  tree[(1 << 3) * 2];

long long   build(int L, int R, int node) {
	int p = L, q = R, m = (L + R) / 2;
	if (p == q) return tree[node] = in[L];
	return tree[node] = ( (build(p, m, node * 2) % div) * (build(m + 1, q, node * 2 + 1) % div)) % div;
}

long long  getsum(int L, int R, int node, int from, int to) {
	int p = L, q = R, m = (L + R) / 2;
	if (from > R || to < L) return 1;
	if (from >= L && to <= R) return tree[node];
	return  (getsum(p, m, node * 2, from, to) % div) * (getsum(m + 1, q, node * 2 + 1, from, to) % div);
}

int a, b, c;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
	}
	build(1, N, 1);
	for (int i = 1; i <= M + K; i++) {
		scanf("%d %d %d", &a, &b, &c) {
			if (a == 1) {
				rebuild()
			}
		}
	}
    
}