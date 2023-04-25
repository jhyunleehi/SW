#include <stdio.h>
int  t[2],m[2],s[2];
int  T, M, S;
int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 0; i < 3; i++) {
		for (int i = 0; i < 2; i++) {
			scanf("%d %d %d", &t[i],&m[i], &s[i]);
		}
		S = s[1] - s[0];
		M = m[1] - m[0];
		T = t[1] - t[0];
		if (S < 0) {
			M--; S += 60;
		}
		if (M < 0) {
			T--; M += 60;
		}
		printf("%d %d %d\n", T, M, S);
	}
	return 0;
}