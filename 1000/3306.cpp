#include<stdio.h>
int N,M[100][2],a;

void call(int i) {
	int B = (M[i][0] < M[i][1]) ? M[i][0] : M[i][1];
	while (B >= 2) {
		if (M[i][0] % B == 0 && M[i][1] % B == 0) {
			M[i][0] = M[i][0] / B;
			M[i][1] = M[i][1] / B;
			B = (M[i][0] < M[i][1]) ? M[i][0] : M[i][1];
			continue;
		}
		B--;
	}
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d", &a);
	for (int i = 1; i < N; i++) {
		scanf("%d", &M[i][1]);
		M[i][0] = a;
	}
	for (int i = 1; i < N; i++) call(i);
	for (int i = 1; i < N; i++)
		printf("%d/%d\n", M[i][0], M[i][1]);

	return 0;
}