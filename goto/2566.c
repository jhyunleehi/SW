#include <stdio.h>
int n, max,ar,ac;
inline int get_int() {
	int rtn = 0;
	char ch = 0;
	while ((ch = getchar()) <= '9' && ch >= '0') {
		rtn = (rtn << 3) + (rtn << 1) + (ch - '0');
	}
	return rtn;
}
int main() {
	freopen("data.txt", "r", stdin);
	for (int r = 1; r <= 9; r++) {
		for (int c = 1; c <= 9; c++) {
			//scanf("%d", &n);
			n = get_int();
			if (max < n) {
				max = n; ar = r; ac = c;
			}
		}
	}
	printf("%d\n%d %d\n", max, ar, ac);
	return 0;
}