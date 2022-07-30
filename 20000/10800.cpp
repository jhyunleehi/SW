#include <stdio.h>
char rbuf[1 << 10];
int sum;

void readrbuf() {
	fread(rbuf, 1, 1 << 10, stdin);
}
char getbyte() {
	static int bidx = -1;
	if (bidx == -1) { readrbuf(); bidx = 0;}
	if (bidx == 1 << 20) {readrbuf(); bidx = 0;}	
	return rbuf[bidx++];
}

int getInt() {
	int temp = 0;
	char ch = getbyte();
	if (ch == '\0') return EOF;
	temp = ch - '0';
	while ((ch = getbyte()) >= '0' && (ch <= '9')) {		
		temp = (temp *10) + (ch - '0');
	}
	return temp;
}
int main() {
	freopen("data.txt", "r", stdin);		
	int num = 0;
	while ((num = getInt()) != EOF) {
		sum += num;		
	}
	printf("%d\n", sum);	
	return 0;
}