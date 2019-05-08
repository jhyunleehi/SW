#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int A, B;
	int *N;
	scanf("%d %d", &A, &B);
	N = (int*)malloc(sizeof(int)*A + 1);
	for (int i = 0; i < A; i++) scanf("%d", N + i);
	int max = 0;
	for (int i = 0; i < B; i++) {
		max += *(N + i);
	}
	int temp = max;
	for (int i = B; i < A; i++) {
		temp = temp + *(N + i) - *(N + (i-B));
		if (max < temp) max = temp;
		//printf("%d %d\n", temp, max);
	}
	printf("%d\n",max);
}
