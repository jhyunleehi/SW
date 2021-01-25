#include<stdio.h>

int a, b, m[2002],k, ans;

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &a, &b);
	int chk = 1;
	for (int i = 1; chk; i++) {
		for (int j = 1; j <= i; j++) {
			m[++k] = i;
			if (k >= 1000) chk = 0;
		}
	}
	for (int i = a; i <= b; i++) {
		ans += m[i];
	}
	printf("%d\n", ans);
	return 0;
}