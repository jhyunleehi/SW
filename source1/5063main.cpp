#include<stdio.h>
int main() {
	int n, a, b, c;
	freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a < (b - c)) printf("advertise\n");
		else if (a == (b - c))  printf("does not matter\n");
		else printf("do not advertise\n");
	}
	return 0;
}