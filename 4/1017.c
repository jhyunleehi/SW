#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

void printDP(int DP[][501], int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			printf("[%d]", *(*(DP + i) + j));
		}
		printf("\n");
	}
	printf("---------------\n");
}

int main() {
	freopen("Text.txt", "r", stdin);
	int N;
	int IS[502][3] = { 0, };
	int DP[502][501] = { 0, };
	scanf("%d", &N);	
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &IS[i][0], &IS[i][1], &IS[i][2]);
	DP[0][1] = 1;
	for (int i = 1; i < N; i++) { //단계 1단계에 갈수 있는 경우수를 계산...
		for (int j = i+1; j <= N; j++) {
			if ((IS[i][0] + IS[i][1]) < IS[j][0]) break;
			DP[i][j] = ((DP[i - 1][j]) > 0) ? (DP[i - 1][j]) + 1 : (DP[i - 1][i]);
		}
		printDP(DP, N, N);
	}
	for (int k = N; k >=2; k--) { //IS 값
		int i = N+(N-k); // DP 값
		if (IS[k][2] == 0) continue;
		for (int j = k - 1; j > 0; j--) {
			if ((IS[k][0] - IS[k][1]) > IS[j][0]) break;
			if (DP[i - 1][k] == 0){
				int m = i-1;
				while ((DP[m][k] == 0) && (m >= N))  m--; 
				//printf("%d: %d: %d \n", i,m, DP[m][k]);
				DP[i - 1][k] = DP[m][k];
			}
			DP[i][j] = (DP[i - 1][j] > 0) ? (DP[i - 1][j] + 1) : DP[i - 1][k];
		}
		printDP(DP, N*2, N);
	}
	int max = 0;
	for (int i = 1; i <= 2 * N - 2; i++)
		if (max < DP[i][1]) max = DP[i][1];
	printf("%d\n", max);
}
