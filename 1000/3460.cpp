#include <stdio.h>
int m[101], n, sum,max,ans;
int main() {
	int t = 10;
	while (t--) {
		scanf("%d", &n);
		m[n / 10]++;
		sum += n / 10;
	}
	for (int i = 1; i <= 100; i++) {
		if (m[i] > max) {
			max = m[i];
			ans = i * 10;
		}
	}
	printf("%d %d\n", sum, ans);
}