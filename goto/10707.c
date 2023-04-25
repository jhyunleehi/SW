#include <stdio.h>
int A, B, C, D, P, ans[2];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d %d",&A,&B,&C,&D,&P);
	ans[0] = A * P;
	if (P > C) {
		ans[1] = B + (P - C) * D;
	}
	else {
		ans[1] = B;
	}
	printf("%d\n", ans[0] < ans[1] ? ans[0] : ans[1]);
	
	return 0;
}