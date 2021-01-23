#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int DT[16] = { 0, };

int call(int n) {	
	if (n == 0) return 2;
	if (n == 1) return 3;
	if (!DT[n])	DT[n] = call(n - 1) + call(n - 1) -1;
	return DT[n];
}

int main() {
	freopen("data.txt", "r", stdin);
	int N, cnt;
	scanf("%d", &N);
	cnt = call(N);
	printf("%d", cnt*cnt);
}
