/*
1. 소수와 함께하는 여행
2. 소수 목록을 추출
3. 소수 목록간 그래프 구성
4. BFS 탐색을 통해서 최소 경로 탐색
5. 소수구하기 https://twpower.github.io/79-usage-of-memset-function
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	int S, E;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &S, &E);
	int prime[9999 + 1]; //0000 ~ 9999 
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= 9999; i++) {
		if (prime[i] == 0) {
			for (int j = i * 2; j <= 9999; j += i) {
				prime[j] = 1;
			}
		}
	}
	int k = 0;
	for (int i = 1000; i <= 9999; i++) {
		if (prime[i] == 0) printf("%d %d %d \n",i, prime[i], k++);
	}
	
}
