#include <stdio.h>
int T, N, M, S[501],cnt,a;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= M; i++) S[i] = 0;
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a);
			if (S[a] == 0) S[a] = 1;
			else cnt++;
		}
		printf("%d\n", cnt);
	}	
	return 0;
}