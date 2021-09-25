#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

int M[2] = { 0, };
int call(int n) {
	//printf("call %d\n", n );	
	if (n == 0) return M[0];
	if (n == 1) return M[1];
	int temp;
	for (int i = 2; i <= n; i++) {
		temp = M[0] + M[1];
		M[0] = M[1];
		M[1]= temp;
		if (M[1] >= 10000) M[1] = M[1] % 10000;
		//if (M[0] > 10000) M[0] = M[0] % 10000;
		//printf("[%d] ", M[1]);
	}		
	return M[1];
}

int main() {
	freopen("data.txt", "r", stdin);
	int N = 0;	
	scanf("%d", &N);
	while (N != -1) {
		M[0] = 0;
		M[1] = 1;
		printf("%d\n", call(N) );
		scanf("%d", &N);
	}
}
