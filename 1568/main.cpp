#include <stdio.h>
int n,m, count;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	m = 1;
	while (n>0) {
		//printf("%d %d [%d]\n", n, m,count);
		if (n >= m) {
			n -= m;
			m++;
			count++;
		}
		else {
			m = 1;
		}
	}
	printf("%d\n", count);
	return 0;
}