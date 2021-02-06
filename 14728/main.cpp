#include <stdio.h>
int N, T, K[101], S[101], dp[101][10001];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &T);
	for (int i = 1; i <= N; i++) scanf("%d %d", &K[i], &S[i]);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < K[i]; j++) dp[i][j] = dp[i-1][j];
		for (int j = K[i]; j <= T; j++)
			dp[i][j] = (dp[i - 1][j] < dp[i - 1][j - K[i]] + S[i]) ? dp[i - 1][j - K[i]] + S[i] : dp[i - 1][j];
	}
	printf("%d\n", dp[N][T]);
	return 0;
}