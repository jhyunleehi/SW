#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<ctime>

#define D_VAL 20091024

typedef unsigned long long ll;

int main() {
	freopen("Text.txt", "r", stdin);
	clock_t t0 = clock();
	int A, B, C;
	ll s10 = 1;
	ll ss = 1;
	scanf("%d %d", &A, &B);
	if (A > D_VAL) A = A % D_VAL;
	for (int i = 0; i < 10; i++) {
		s10 = A * (s10%D_VAL);
	}
	printf("%llu\n", s10%D_VAL);
	ss = s10;
	for (int k = 1000000000; k >= 10; k = k / 10) {
		C = B / k;
		B = B % k;		
		if (C >= 1) {
			for (int i = 10; i < k; i *= 10) {
				ss = 10 * (ss%D_VAL);
			}
			for (int i = 1; i < C; i++) {
				ss = s10 * (ss%D_VAL);
			}
		}
	}
	for (int i = 1; i <= B; i++) {
		ss = A * (ss%D_VAL);
	}
	printf("%llu\n", ss%D_VAL);

	printf("%.3f\n", (float)(clock() - t0) / CLOCKS_PER_SEC);
}
