#include <stdio.h>
int a[4],s;
int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	printf("%d\n%d\n", s / 60, s % 60);	
	return 0;
}