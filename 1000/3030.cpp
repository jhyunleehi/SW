#include <stdio.h>
int n[10];
int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 1; i <= 9; i++) scanf("%d", &n[i]);
	for (int i = 1; i < 9; i++) {
		for (int j = i + 1; j <= 9; j++) {
			int sum = 0;
			for (int k = 1; k <= 9; k++) {
				if (k == i || k == j) continue;
				sum += n[k];
			}
			if (sum == 100) {
				for (int k = 1; k <= 9; k++) {
					if (k == i || k == j) continue;
					printf("%d\n", n[k]);
				}
			}
		}
	}	
	return 0;
}