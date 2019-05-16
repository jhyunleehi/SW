#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

int N, A, B;
void call_dfs(int **M, int **C, int **V, int y, int x) {
	printf("call: %d %d \n", y, x);
	int ny, nx;
	int h1, t1, t2;
	int dy[] = { 0,-1,0,1 };
	int dx[] = { -1,0,1,0 };
	*(*(V + y) + x) = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];		
			if ((ny >= 1) && (ny <= N) && (nx >= 1) && (nx <= N)) {
				h1 = *(*(M + y) + x) - *(*(M + ny) + nx);
				t1 = *(*(C + ny) + nx);
				t2 = *(*(C + y) + x);
				if ( *(*(V+ny)+nx) == 0 ) {
					if ((h1 > 0) && (t1 > h1*h1 + t2)) {
						*(*(C + ny) + nx) = h1 * h1 + t2;
						call_dfs(M, C, V, ny, nx);
					}
					if ((h1 < 0) && (t1 > -1 * h1 + t2)) {
						*(*(C + ny) + nx) = -1 * h1 + t2;
						call_dfs(M, C, V, ny, nx);
					}
					if ((h1 == 0) && (t1 > t2)) {
						*(*(C + ny) + nx) = t2;
						call_dfs(M, C, V, ny, nx);
					}
				}
			}
		
	}
	//for (int i = 0; i <= N+1; i++) {
	//	for (int j = 0; j <= N+1; j++) 	printf("%3d ", *(*(C + i) + j));		
	//	printf("\n");
	//}
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d %d", &A, &B);
	int **M = (int**)malloc(sizeof(int*)*N + 2);
	int **C = (int**)malloc(sizeof(int*)*N + 2);
	int **V = (int**)malloc(sizeof(int*)*N + 2);
	for (int i = 0; i <= N + 1; i++) *(M + i) = (int*)malloc(sizeof(int)*N + 2);
	for (int i = 0; i <= N + 1; i++) *(C + i) = (int*)malloc(sizeof(int)*N + 2);
	for (int i = 0; i <= N + 1; i++) *(V + i) = (int*)malloc(sizeof(int)*N + 2);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", *(M + i) + j);
		}
	for (int i = 0; i <= N + 1; i++)
		for (int j = 0; j <= N + 1; j++) {
			*(*(C + i) + j) = 0x7FFFFFFF;
			*(*(V + i) + j) = 0;
		}
	*(*(C + A) + B) = 0;
	call_dfs(M, C, V, A, B);
	int max = 0x7FFFFFFF;
	int temp1, temp2;
	for (int i = 1; i <= N; i++) {
		temp1 = *(*(M + 1) + i) * *(*(M + 1) + i);
		temp2 = *(*(C + 1) + i);
		*(*(C + 0) + i) = temp1 + temp2;
		if (max > temp1 + temp2)  max = temp1 + temp2;
	}
	for (int i = 1; i <= N; i++) {
		//if (max > M[N][i] * M[N][i] + C[N][i])  max = M[N][i] * M[N][i] + C[N][i];
		temp1 = *(*(M + N) + i) * *(*(M + N) + i);
		temp2 = *(*(C + N) + i);
		*(*(C + N + 1) + i) = temp1 + temp2;
		if (max > temp1 + temp2)  max = temp1 + temp2;
	}
	for (int i = 1; i <= N; i++) {
		//if (max > M[i][1] * M[i][1] + C[i][1])   max = M[i][1] * M[i][1] + C[i][1];
		temp1 = *(*(M + i) + 1) * *(*(M + i) + 1);
		temp2 = *(*(C + i) + 1);
		*(*(C + i) + 0) = temp1 + temp2;
		if (max > temp1 + temp2)  max = temp1 + temp2;
	}
	for (int i = 1; i <= N; i++) {
		//if (max > M[i][N] * M[i][N] + C[i][N])   max = M[i][N] * M[i][N] + C[i][N];
		temp1 = *(*(M + i) + N) *  *(*(M + i) + N);
		temp2 = *(*(C + i) + N);
		*(*(C + i) + N + 1) = temp1 + temp2;
		if (max > temp1 + temp2)  max = temp1 + temp2;
	}
	printf("%d\n", max);
}
