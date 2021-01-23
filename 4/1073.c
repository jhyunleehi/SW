#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

int map[51][51][51] = { 0, };
void qsort(int *M, int L, int R) {
	int p = L;
	int q = R;
	int m = (*(M + L) + *(M + R)) / 2;
	while (p <= q) {
		while (*(M + p) > m) p++;
		while (*(M + q) < m) q--;
		if (p <= q) {
			int temp = *(M + p);
			*(M + p) = *(M + q);
			*(M + q) = temp;
			p++; q--;
		}
	}
	if (L < q) qsort(M, L, q);
	if (R > p) qsort(M, p, R);
}

void call(int *M, int N, int A, int B, int C, int *max) {
	if (map[A][B][C] != 0) return;
	map[A][B][C] = 1;
	map[B][C][A] = 1;
	map[C][A][B] = 1;
	printf("%d %d %d :%d\n", A, B, C, *max);
	if ((A >= N) || (B >= N) || (C >= N)) return;
	if ((A != B) && (B != C) && (A != C)) {
		//if ((*(M + A) + *(M + B) > *(M + C)) && (*(M + C)>= *(M + A)) &&(*(M + C) >= *(M + B))) {

		if (((*(M + A) + *(M + B) > *(M + C))) && (*(M + C) + *(M + B) > *(M + A)) && (*(M + C) + *(M + A) > *(M + B))){
			if (*max < (*(M + A) + *(M + B) + *(M + C)))
				*max = (*(M + A) + *(M + B) + *(M + C));
		}
	}	
	call(M, N, ++A, B, C, max);
	call(M, N, A, ++B, C, max);
	B--;
	call(M, N, A, B, ++C, max);
	C--;
}

int main() {
	freopen("data.txt", "r", stdin);
	int N = 0;
	int *M;
	int max = 0;
	scanf("%d", &N);
	M = (int *)malloc(sizeof(int)*N + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", M + i);
	}
	qsort(M, 0, N - 1);
	for (int i = 0; i < N; i++)
		printf("%d ", *(M + i));
	call(M, N, 0, 0, 0, &max);
	printf("%d\n", max);
}
