#include <stdio.h>

int T, N, D, V, F, C, ans;
int main()
{
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%d %d", &N, &D);
		for (int j = 0; j < N; j++) {
			scanf("%d %d %d", &V, &F, &C);
			if ((V * F / C) >= D) ans++;
		}
		printf("%d\n", ans);
	}
}
