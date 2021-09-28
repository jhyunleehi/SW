#include <stdio.h>
int a,b,c,d,e;
int main() {
	scanf("%d %d %d",&a,&b,&c);
	int ab = (a + 1) * (b + 1);
	d = ab / (c + 1);
	e = d - 1;
	if (e < 0) printf("%d\n", e * -1);
	else printf("%d\n", e);
	return 0;
}