#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int N, K;
	int M[100000 + 2][2];
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M[i][0]);
	}
	long long sum = 0;
	long long max = 0x7FFFFFFFFFFFFFFF + 1;
	for (int i = 1; i <= K; i++) sum += M[i][0];
	//M[K][1] = sum;
	if (max < sum) max = sum;
	for (int i = K + 1; i <= N; i++) {
		sum = sum + M[i][0] - M[i - K][0];
		if (sum > max) max = sum;
		printf("%d %d \n", M[i][0], sum);
	}
	printf("%lld\n", max);
}
