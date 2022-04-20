#include <stdio.h>
int n;
char ch;
int get_int() {
	int n = 0;
	int minus = 1;
	char ch = getchar();
	if (ch == '-') minus = -1;
	n = (ch - '0');
	while ('0' <= (ch = getchar()) && ch <= '9') {
		n = (n * 10) + ch - '0';
	}
	return n * minus;
}
int main() {
	freopen("data.txt", "r", stdin);
	n = get_int();
	while (n--) {
		bool whead = true;
		while ((ch=getchar()) != '\n') {
			if(whead) {
				if (ch>='a' && ch<='z')  
					printf("%c", (ch-'a') + 'A');
				else 
					printf("%c", ch);
				whead = false;
			}
			else {
				printf("%c", ch);
			}
		}
		if (ch == ' ') whead = true;
		printf("\n");
	}
	
	return 0;
}