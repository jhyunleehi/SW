#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
int M[1,000,000,000 + 1] = {0,};

int call(int n) {
	printf("call n:%d M:%d\n", n, M[n]);
	if (M[n] != 0) return M[n];
	if (n == 0) return M[0];
	if (n == 1) return M[1];
	M[n] = call(n - 1) + call(n - 2);
	if (M[n] > 1000) M[n] % 1000;
	return M[n];
}

int main() {
	freopen("data.txt", "r", stdin);
	int N = 0;
	M[0] = 0;
	M[1] = 1;
	scanf("%d", &N);
	while (N != -1) {
		printf("%d", call(N) );
		scanf("%d", &N);
	}
}
