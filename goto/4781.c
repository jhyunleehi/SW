#include <stdio.h>
#include <memory.h>
#define MAX(A,B)  (((A)>(B))?(A):(B))

int N, M, m1, m2;
int c[5001], p[5001];
int dp[10001];  //M * N
int main() {
	freopen("data.txt", "r", stdin);
	while(1){
		int max = 0;
		scanf("%d %d.%d", &N, &m1, &m2); M = m1 * 100 + m2;		
		if (N == 0) break;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; i++) { 
			scanf("%d %d.%d", &c[i], &m1, &m2); 
			p[i] = m1 * 100 + m2;			
		}
		for (int i = 1; i <= N; i++) {
			for (int j = p[i]; j <= M; j++) {
				if (dp[j] < dp[j-p[i]]+c[i]) {
					dp[j] = dp[j - p[i]] + c[i];
					max = MAX(dp[j], max);
				}
			}
		}				
		printf("%d\n", max);		
	}
	return 0;
}
