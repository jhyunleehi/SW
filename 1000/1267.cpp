#include <stdio.h>
int N, n, sum;
int main() {
	freopen("data.txt", "r", stdin);
	int y = 0, m = 0;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &n);		
		y += ((n / 30) + 1) * 10;
		m += ((n / 60) + 1) * 15;		
	}
	if (y > m) {
		printf("M %d\n", m);
	}
	else if (m > y) {
		printf("Y %d\n", y);
	}
	else if (m == y) {
		printf("Y M %d\n", y);
	}
	return 0;
}