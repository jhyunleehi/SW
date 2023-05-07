#include<stdio.h>
int K, N,a;
unsigned short m[1000];
int main() {
	freopen("data.txt", "r", stdin);	
	scanf("%d %d", &K, &N);
	for (int i = 2; i <= K; i++) {
		for (int j = i; j <= K; j += i)
			if (m[j] == 0) {
				m[j] = ++a;
				if (a == N) {
					printf("%d", j);
					return 0;;
				}
			}
	}
	return 0;
}