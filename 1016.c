#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
int main() {
	int M[1001];
	int N = 0;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M[i]);
	}
	int i = 1;
	int k = N;
	int cnt = 0;
	while (i < k) {
		i = 1;
		while (M[i] <= M[i + 1]) i++;
		k = N;
		while (M[k] >= M[i]) k--;
		if (i < k) {
			int temp = M[i];
			M[i] = M[k];
			M[k] = temp;
			cnt++;
		}

		for (int j = 1; j <= N; j++) {
			printf("[%d]", M[j]);
		}
		printf("\n");
	}

}
