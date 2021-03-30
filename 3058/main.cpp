#include <stdio.h>
int T, sum, min, a;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		sum = 0; min = 0x7FFFFFFF;
		for (int i = 1; i <= 7; i++) {
			scanf("%d", &a);
			if (a % 2 == 0) {
				sum += a;
				min = (min > a) ? a: min;
			}
		}
		printf("%d %d\n", sum, min);
	}	
	return 0;
}