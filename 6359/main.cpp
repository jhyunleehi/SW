#include<stdio.h>
int t, n;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		int m[101] = { 0, };
		for (int j = 2; j <= n; j++) {
			for (int k = j; k <= n; k += j) {
				m[k] = (m[k]) ? 0 : 1;
			}
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++) if (!m[j]) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}