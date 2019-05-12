#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

void call(unsigned long long *sum, int N) {
	//printf("%lld %d\n", *sum,N);
	if (N == 0) return;
	*sum *= N;
	call(sum, --N);
}


int main() {
	freopen("data.txt", "r", stdin);
	int M[20][2] = { 0, };
	int N;
	unsigned long long sum = 1;
	scanf("%d", &N);
	call(&sum, N);
	int cnt = 0;
	
	while (sum >= 10) {
		M[cnt++][0] = sum % 10;		
		sum = sum / 10;
	}
	M[cnt][0] = sum;
	int max = 0;
	for (int i = 0; i <= cnt; i++) {
		if (M[i][0] == 0) {
			if (i > 0)
				M[i][1] = M[i - 1][1] + 1;
			else
				M[i][1] = 1;
			if (max < M[i][1]) max = M[i][1];
		}
		else {
			M[i][1] = 0;
		}
	}	
	//for (int i = 0; i <= cnt; i++) printf("[%d] [%d]\n", M[i][0], M[i][1]);
	printf("%d\n", max);	
}
