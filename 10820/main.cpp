#include <stdio.h>
int ch;
int a, b, c, d;
int main() {
	freopen("data.txt", "r", stdin);
	while ((ch = getchar()) != EOF) {
		if (ch >= 'a' && ch <= 'z') a++;
		if (ch >= 'A' && ch <= 'Z') b++;
		if (ch >= '0' && ch <= '9') c++;
		if (ch == ' ') d++;
		if (ch == '\n') {
			if (a+b+c+d != 0) printf("%d %d %d %d\n", a, b, c, d);
			a = b = c = d = 0;
		}
	}
	if (a + b + c + d != 0) printf("%d %d %d %d\n", a, b, c, d);
	return 0;
}