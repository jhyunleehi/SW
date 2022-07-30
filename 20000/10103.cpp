#include <stdio.h>
int N, S[2] = { 100,100 }, a, b;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&N);
	while (N--) {
		scanf("%d %d", &a, &b);
		if (a < b)  S[0] -= b; 
		if (b < a) S[1] -= a;
	}
	printf("%d\n%d\n", S[0], S[1]);
	return 0;
}