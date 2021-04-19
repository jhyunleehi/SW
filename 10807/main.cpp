#include <stdio.h>
int in[101 * 2]; //-100~100
int a, b,c;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&a);
	while (a--) { scanf("%d", &b); in[b + 100]++; }
	scanf("%d", &c);
	printf("%d", in[c + 100]);
	return 0;
}