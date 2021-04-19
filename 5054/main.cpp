#include <stdio.h>
int T, n, s;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int min = 100, max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &s);
			max = (max < s) ? s : max;
			min = (min > s) ? s : min;
		}		
		printf("%d\n", (max - min) * 2);
	}
	return 0;
}