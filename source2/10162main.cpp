#include <stdio.h>
int a, b, c, n;
int a1 = 300, b1 = 60, c1 = 10;
int main() {
	scanf("%d",&n);
	a = n / a1;
	n = n % a1;
	b = n / b1;
	n = n % b1;
	c = n / c1;
	n = n % c1;
	if (n)
		printf("%d\n", -1);
	else
		printf("%d %d %d\n", a, b, c);
	return 0;
}