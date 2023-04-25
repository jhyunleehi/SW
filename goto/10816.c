#include <stdio.h>
int n,m,h[20000003],a;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		h[a + 10000000]++;
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &a);
		printf("%d ", h[a + 10000000]);
	}
	printf("\n");
	return 0;
}