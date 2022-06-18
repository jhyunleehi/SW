#include <stdio.h>
int n[3], t[3], s,ans;
int main() {
	scanf("%d %d %d",&n[0],&n[1],&n[2]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				if (n[i] == n[j]) t[i]++;
			}
		}
	}
	int max = 0;
	int m = 0;
	for (int i = 0; i < 3; i++) {
		s += t[i];
		max = (max > n[i]) ? max : n[i];
		if (t[i] == 1) m = i;
	}
	if (s == 6) {
		ans = 10000 + n[0] * 1000;
	}
	if (s == 2) {
		ans = 1000 + n[m] * 100;

	}
	if (s == 0) {
		ans = max * 100;
	}
	printf("%d", ans);
}