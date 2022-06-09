#include <stdio.h>
int N, K;
int a;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		if ((i * i) == K) {
			a = i;
			break;
		}
		if ((i * i) > K) {
			a = i-1;
			break;
		}
	}
	printf("%d\n", a);
	return 0;
}