#include <stdio.h>
int n, L[21], J[21], dp[101];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d", &L[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &J[i]);
	for (int i = 1; i <= n; i++) {		
		for (int j = 100; j >= L[i]; j--)
			dp[j] = (dp[j] < dp[j - L[i]] + J[i]) ? dp[j - L[i]] + J[i] : dp[j];
	}
	printf("%d\n", dp[99]);
	return 0;
}