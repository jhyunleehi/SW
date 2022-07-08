#include<stdio.h>

int N;
int m[32],idx;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);	
	for (int i = 2; i <= N; i++) {
		if ((N / i == 1) && (N % i == 0)) {
			printf("%d\n", i);
			break;
		}
		if (N % i == 0) {
			N = N / i;
			printf("%d\n", i);		
			i = 1;
		}
	}
	return 0;
}