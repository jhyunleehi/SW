#include <stdio.h>
const int div = 1000000007;
int N, M, K;
int in[1 << 20];
long long  ctree[(1 << 20) * 2];

long long   build(int L, int R, int node) {
	int p = L, q = R, m = (L + R) / 2;
	if (p == q) return ctree[node] = in[L];
	return ctree[node] = ((build(p, m, node * 2) % div) * (build(m + 1, q, node * 2 + 1) % div)) % div;
}

long long  getsum(int L, int R, int node, int from, int to) {
	int p = L, q = R, m = (L + R) / 2;
	if (from > R || to < L) return 1;
	if (from <= L  && to >= R ) return ctree[node];
	return  (getsum(p, m, node * 2, from, to) % div) * (getsum(m + 1, q, node * 2 + 1, from, to) % div);
}

void rebuild(int L, int R, int node, int key, int value) {
	int p = L, q = R, m = (L + R) / 2;
	if (key<p || key >q) return;
	ctree[node] = ctree[node]  / in[key];
	ctree[node] = (ctree[node] * value) % div;
	if (p == q) return;
	rebuild(p, m, node * 2, key, value);
	rebuild(m + 1, q, node * 2 + 1, key, value);
}

void rebuild_b(int L,int R, int node, int value) {
	int child = node, parent = child / 2;
	ctree[child] = value % div;
	while (parent > 0) {
		ctree[parent] = (ctree[parent * 2] * ctree[parent * 2 + 1])%div;
		child = parent;
		parent = child/2;
	}
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
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			int p = 1, q = N, m = (p + q) / 2, node=1;
			while (p != q) {
				m = (p + q) / 2;
				if (p == q) break;
				if (b <= m) { 
					p = p; q = m; node = node * 2; 
				}
				else {
					p = m + 1; q = q; node = node * 2 + 1;
				}
			}
			rebuild_b(1, N, node, c);
			//rebuild(1,N,1,b,c);
		}else  if (a == 2) {
				printf("%lld\n", getsum(1, N, 1, b, c) % div);
		}
	}

}