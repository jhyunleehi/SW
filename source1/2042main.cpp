#include <stdio.h>
int N, M, K;
long long ctree[1000001 * 4], in[1000001 * 2];

long long build(int S, int E, int node) {
	if (S == E) return ctree[node] = in[S];
	int mid = (S + E) / 2;
	return ctree[node] = build(S, mid, node * 2) + build(mid + 1, E, node * 2 + 1);
}

long long sum(int S, int E, int node, int p, int q) {
	if (p > E || q < S) return 0;
	if (p <= S && q >= E) return ctree[node];
	int mid = (S + E) / 2;
	return sum(S, mid, node * 2, p, q) + sum(mid + 1, E, node * 2 + 1, p, q);
}

void rebuild(int S, int E, int node, int index, long long diff) {
	if (index < S || index > E) return;
	ctree[node] += diff;
	if (S != E) {
		int mid = (S + E) / 2;
		rebuild(S, mid, node * 2, index, diff);
		rebuild(mid + 1, E, node * 2 + 1, index, diff);
	}
}


long long a, b, c;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
	}
	build(1, N, 1);
	for (int i = 1; i <= M + K; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 2) {
			long long ans = sum(1, N, 1, b, c);
			printf("%lld\n", ans);
		}
		else if (a == 1) {
			long long diff = c - in[b];
			in[b] = c;
			rebuild(1, N, 1, b, diff);
		}
	}
	return 0;
}