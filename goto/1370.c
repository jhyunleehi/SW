#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

void qsort(int M[][4], int L, int R) {
	//printf("call: %d, %d \n", s, e);	
	int p = L;
	int q = R;
	int v = M[(L + R) / 2][2];
	int temp[3] = { 0, };
	while (p <= q) {		
		while (M[p][2] < v ) p++;
		while (M[q][2] > v ) q--;
		if (p <= q) {
			for (int i = 0; i < 3; i++) { 
				temp[i] = M[p][i]; 
				M[p][i] = M[q][i];
				M[q][i] = temp[i];
			}
			p++; q--;
		}		
	}
	if(L<q) qsort(M, L, q);
	if(R>p) qsort(M, p, R);
}

int M[501][4];

int main() {
	int N;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &(M[i][0]), &(M[i][1]), &(M[i][2]));
	}
	qsort( M, 1, N);

	//for (int i = 1; i <= N; i++) {printf("%d %d %d\n", M[i][0], M[i][1], M[i][2]);}


	M[1][3] = 1;
	int cnt=1;
	for (int i=1; i<=N; i++){
		for (int j = i + 1; j <= N; j++) {
			if (M[j][1] >= M[i][2]) {				
				M[j][3] = 1;
				i = --j;
				cnt++;
				break;
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= N; i++) {
		if (M[i][3] == 1) printf("%d ", M[i][0]);
	}
}
