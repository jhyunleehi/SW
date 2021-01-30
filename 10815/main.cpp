#include<stdio.h>

char m[20000002];

int get_int() {
	bool m = false;
	int r = 0;
	char ch='\0';
	if ((ch = getchar()) == '-') m = true;
	else r = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9') {
		r = (r << 3) + (r << 1) + ch - '0';
	}
	return r = (m) ? r * -1 : r;
}
int N, M;
int main() {
	freopen("data.txt", "r", stdin);
	N = get_int();
	while (N--) {
		m[get_int() + 10000000] = 1;
	}
	M = get_int();
	while (M--) {
		printf("%d ", m[get_int() + 10000000]);
	}
	return 0;
}