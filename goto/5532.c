#include<stdio.h>

int D, A, B, a, b;

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d %d", &D, &A, &B, &a, &b);
	int t1 = (((A * 10) / a) + 9) / 10;
	int t2 = (((B * 10) / b) + 9) / 10;
	printf("%d\n", (t1 > t2) ? D - t1 : D - t2);
	return 0;
}
