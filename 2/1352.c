/*
양팔 저울
1. 추를 왼쪽, 오른쪽, 선택하지 않는 3가지 경우로 나눠서 전체 탐색
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int N, M;
int *C;
int *G;
int *Map;
int Mp[30 * 500];
int Mm[30 * 500];
int cp[30 * 500];
int cm[30 * 500];


void call(int n, int w) { //n: 추단계, w: weight	
	//printf("call: %d %d \n", n, w);
	int i = 0;	
	bool dup = false;
	//여기 부분을 단축이 필요하다.
	while (*(Map+i) != 0 ) {
		if (*(Map + i) == w) {
			dup = true;
			break;
		}
		i++;
	}
	if (!dup) *(Map + i) = w;
	if (n >= N) return;
	call(n + 1, w - *(C + n)); //왼쪽 선택
	call(n + 1, w + *(C + n)); //오른쪽 선택
	call(n + 1, w );           //선택하지 않음 
}

void qsort(int L, int R) {
	//printf("sort: %d %d \n", L, R);
	int p = L;
	int q = R;
	int v = *(Map + (L + R) / 2);
	while (p <= q) {
		while (*(Map+p) < v) p++;
		while (*(Map+q) > v) q--;
		if (p <= q) {
			int temp = *(Map + p);
			*(Map + p) = *(Map + q);
			*(Map + q) = temp;
			p++; q--;
		}
	}
	if(L<q) qsort(L, q);
	if(R>p) qsort(p, R);
}

bool find(int s, int e, int n) {
	if (s > e) return false;
	int m = ((s + e) / 2);
	int v = *(Map + m);
	if (v == n) return true;
	if (v > n)
		return find(s, m-1, n);
	else
		return find(m + 1, e, n);
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	C = (int*)malloc(sizeof(int)*N + 1);

	Map = (int*)malloc(sizeof(int)*(1024*1024) + 1);	
	for (int i = 0; i < 1024*1024; i++) *(Map + i) = 0;

	for (int i = 0; i < N; i++) scanf("%d", (C + i));
	//for (int i = 0; i < N; i++)	printf("%d", *(C + i));	printf("\n");
	scanf("%d", &M);
	
	G = (int*)malloc(sizeof(int)*M + 1);
	for (int i = 0; i < M; i++)scanf("%d", G + i);
	call(0, 0);
	int length = 0;
	while (*(Map + length) != 0) length++;
	qsort(0, length -1);
	for (int i = 0; i < M; i++) {
		if ( find(0, length - 1, *(G + i)) ) 
			printf("Y ");
		else 
			printf("N ");
	}
}
