#include <stdio.h>
int sum, n;
int main() {
	for (int i = 0; i < 6; i++) {
		scanf("%d", &n);
		sum += n;
	}
	printf("%d\n", sum * 5);
	return 0;
}