#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	int A, B;
	int M,temp;
	int cnt;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A, &B);
		temp=M = A * B;
		cnt = 0;
		while (temp >= 10) {
			cnt++;
			temp = temp / 10;
		}
		cnt++;
		printf("%d %d\n", M, cnt);
	}
}
