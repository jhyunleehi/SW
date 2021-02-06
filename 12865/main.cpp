#include <stdio.h>
int v[101], w[101], N, K;
int dp[10][100001];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d %d", &w[i], &v[i]);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < w[i]; j++) dp[i][j] = dp[i - 1][j];
		for (int j = w[i]; j <= K; j++) {
			dp[i][j] = (dp[i - 1][j] < dp[i - 1][j - w[i]] + v[i]) ? dp[i - 1][j - w[i]] + v[i] : dp[i - 1][j];
		}
	}
	printf("%d\n", dp[N][K]);
	return 0;
}