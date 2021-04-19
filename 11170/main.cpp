#include <stdio.h>
int T, N, M, cnt;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		cnt = 0;
		for (int i = N; i <= M; i++) {
			int temp = i;
			if (temp == 0) cnt++;
			while (temp) {
				if (temp % 10 == 0) cnt++;
				temp = temp / 10;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}