#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	int N;
	char **M;
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	M = (char**)malloc(sizeof(char**));
	for (int i = 0; i <= N; i++) {
		*(M + i) = (char*)malloc(sizeof(char)*N + 1);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", *(M + i) + j);
		}
	}

	printf("\n");

	*(*(M + 0) + 0) = 0;
	for (int i = 1; i <= N; i++) {
		*(*(M + i) + 0) = *(*(M + i) + 1);
		for (int j = 2; j <= N; j++) {
			*(*(M + i) + 0) = *(*(M + i) + 0) ^ *(*(M + i) + j);
		}
	}
	for (int i = 1; i <= N; i++) {
		*(*(M + 0) + i) = *(*(M + 1) + i);
		for (int j = 2; j <= N; j++) {
			*(*(M + 0) + i) = *(*(M + 0) + i) ^ *(*(M + j) + i);
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			printf("[%d]", *(*(M + i) + j));
		}
		printf("\n");
	}
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = 1; i <= N; i++) {
		cnt1 += *(*(M + i) + 0);
		cnt2 += *(*(M + 0) + i);
	}
	if ((cnt1 == 0) && (cnt2 == 0))
		printf("OK\n");
	if (((cnt1 >= 1) && (cnt2 == 0)) || ((cnt1 == 0) && (cnt2 >= 1)))
		printf("Corrupt\n");
	if ((cnt1 == 1) && (cnt2 == 1)) {
		int pos1 = 0;
		int pos2 = 0;
		for (int i = 1; i <= N; i++) {
			if (*(*(M + i) + 0) == 1) pos1 = i;;
			if (*(*(M + 0) + i) == 1) pos2 = i;
		}
		printf("Change bit (%d,%d)\n", pos1, pos2);
	}

}
