#include <stdio.h>
int A, M, m[101], c[101], dp[10001], C;
int main() {
	scanf("%d %d", &A, &M);
	for (int i = 1; i <= A; i++) scanf("%d", m + i);
		for (int i = 1; i <= A; i++) { scanf("%d", c + i); C += c[i]; }
	for (int i = 1; i <= A; i++) {
		for (int j = C; j >= c[i]; j--) 	if (dp[j] < dp[j - c[i]] + m[i]) dp[j] = dp[j - c[i]] + m[i];
	}
	int i;
		for (i = 1; dp[i] < M; i++);
		printf("%d\n", i);
		return 0;
}