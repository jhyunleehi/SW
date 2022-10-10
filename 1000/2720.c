#include <stdio.h>
long long A, B;

long long  get(long long A, long long  B) {
	long long  ans = 0;
	long long  node = (B - A) + 1;
	long long  c = (B + A);
	if (node % 2 == 1) {
		ans = c * (node / 2) + c / 2;
	}
	else {
		ans = c * (node / 2);
	}
	return ans;
}


int main() {
	freopen("data.txt", "r", stdin);
	scanf("%lld %lld",&A, &B);	
	long long ans = 0;
	if (A > B) {
		long long  temp = A;
		A = B; B = temp;
	}
	if (A >= 1) {
		ans=get(A, B);
		printf("%lld\n", ans);
		return 0;
	}else if (B <= -1) {
		ans = get(-1 * B, -1 * A);
		ans = ans * -1;
		printf("%lld\n", ans);
		return 0;
	} else if (A <= 0 && B >=0) {
		ans = get(0, B);
		ans -= get(0, -1*A);
		printf("%lld\n", ans);
	}	
	return 0;
}