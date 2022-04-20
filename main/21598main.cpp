#include <stdio.h>
char rbuf[1 << 2];

void read() {
	fread(rbuf, 1, 1 << 1, stdin);
}
char getByte() {
	static int bidx = -1;
	if (bidx == -1) { read(); bidx = 0; }
	if (bidx == 1 << 1) { read(); bidx = 0; }
	return rbuf[bidx++];
}
int getInt() {
	int temp = 0, minus = 0;
	char ch = getByte();
	if (ch == '-')minus = -1;
	else temp = ch - '0';
	while ((ch = getByte()) >= '0' && ch <= '9') {
		temp = (temp << 3) + (temp << 1) + (ch - '0');
	}
	return (minus == -1) ? temp*-1 : temp;
}
int main() {
	int n = getInt();
	if (n == 1) printf("SciComLove\n");
	else if (n == 2) {
		printf("SciComLove\n");
		printf("SciComLove\n");
	}
	return 0;
}