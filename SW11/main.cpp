#include<stdio.h>

int T, N, M, B;
long long in[200001];
long long temp[200001];
long long dp[51][200001];

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &N, &M, &B);
		for (int b = 0; b <= B; b++) for (int n = 0; n <= N; n++) dp[b][n] = 0;
		for (int i = 0; i <= N; i++) temp[i] = 0;
		for (int i = 1; i <= N; i++) scanf("%d", &in[i]);
		for (int i = 1; i <= M; i++) temp[M] += in[i];
		for (int i = M+1; i <= N; i++) temp[i] = temp[i-1] + in[i] - in[i-M];		
		for (int b = 1; b <= B; b++) {
			for (int n = b * M; n <= N; n++) {				
				dp[b][n] = (dp[b][n - 1] < dp[b - 1][n - M] + temp[n]) ? dp[b - 1][n - M] + temp[n] : dp[b][n - 1];
			}
		}
		printf("#%d %d\n", t, dp[B][N]);
	}
	return 0;
}