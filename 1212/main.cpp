#include <stdio.h>
char ch;
int t, chk, f, b;
int main() {
	while ((ch = getchar()) >= '0' && ch < '9') {
		t = ch - '0';
		if ((f == 0) && (t == 0)) {
			printf("0");			
		}
		else {
			for (int i = 2; i >= 0; i--) {
				b = (t >> i) & 1;
				if ((chk == 0 && b == 0)) continue;
				else {
					chk = 1;
					printf("%d", (t >> i) & 1);
				}
			}
		}
		f = 1;
		chk = 1;

	}
	return 0;
}