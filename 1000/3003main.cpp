#include <stdio.h>
int t[6] = { 1,1,2,2,2,8 };
int s[6];
int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 0; i < 6; i++) {
		scanf("%d", &s[i]);
		printf("%d ", t[i] - s[i]);
	}
	printf("\n");
	return 0;
}