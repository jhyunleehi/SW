#include <stdio.h>
int n;
int main() {
	scanf("%d",&n);
	printf("%d %d", n * 78 / 100, n - ((n - (n * 80 / 100)) * 22 / 100));	
	return 0;
}