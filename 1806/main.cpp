#include <stdio.h>
int n,N[100001],s;
int a, b, sum,ans=200000,length;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &N[i]);
	sum = N[a];
	while ((a <= b) && b<n) {
		if (sum >= s) {
			if ((b-a)+1 < ans) ans = (b - a) + 1;
			sum -= N[a];
			a++;
		}
		else {
			b++;
			sum += N[b];
		}

	}
	if (ans == 200000) printf("0\n");
	else printf("%d\n", ans);
	return 0;
}