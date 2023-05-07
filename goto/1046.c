#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int N;

void  qsort(int *M, int L, int R) {	
	int p = L;
	int q = R;
	int v = *(M + (p + q)/2);
	int temp;
	while (p <= q) {
		//for (int i = 0; i < N; i++) printf("%d ", *(M + i)); printf("\n");
		while (*(M + p) < v) p++;
		while (*(M + q) > v) q--;
		if (p <= q) {
			temp = *(M + p);
			*(M + p) = *(M + q);
			*(M + q) = temp;
			p++; q--;
		}
	}
	if (L < q)qsort(M, L, q);
	if (p < R)qsort(M, p, R);
}

int main() {
	freopen("data.txt", "r", stdin);
;
	int *M;
	scanf("%d", &N);
	M = (int*)malloc(sizeof(int) + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", M + i);
	}
	qsort(M, 0, N - 1);	
	float max = 0.0;
	for (int i = 0; i < N/2; i++) {
		if (max < (*(M + i) + *(M + (N - 1) - i)) /2.0 )
			max = (*(M + i) + *(M + (N - 1) - i)) / 2.0;
	}
	if (N & 1 == 1)
		if (max < (*(M + N / 2)))
			max = *(M + N / 2);
	printf("%.1f\n", max);
}
