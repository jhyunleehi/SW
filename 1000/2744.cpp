#include <stdio.h>
char ch;
int main() {
	while ((ch = getchar()) >= 'A' && ch <= 'z') {
		if (ch <= 'Z')
			printf("%c", ch - 'A' + 'a');
		else
			printf("%c", ch - 'a' + 'A');
	}	
	return 0;
}