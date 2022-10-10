#include <stdio.h>
char str[501];
int scmp(char* s, const char* t) {
	int i = 0;
	while (*(s + i) != '\0' || *(t + i) != '\0') {
		if (*(s + i) < *(t + i)) return  - 1;
		if (*(s + i) > *(t + i)) return  1;
		i++;
	}
	return 0;
}
int slen(char* s) {
	int i = 0;
	while (*(s + i) != '\0') i++;
	return i;
}
void sread() {
	int i = 0;
	char ch = getchar();
	while ((ch  != '\n') &&(ch != '\r')) {
		str[i] = ch;
		ch = getchar();
		i++;
	}
	str[i] = '\0';;
}
int main() {
	freopen("data.txt", "r", stdin);
	while (1) {
		sread();
		if (scmp(str, "END") == 0) break;
		int len = slen(str);
		for (int i = len - 1; i >= 0; i--) 
			printf("%c", str[i]);
		printf("\n");
	}	
	return 0;
}