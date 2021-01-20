#include<stdio.h>
char s[51];
int i, h=10;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%s", s);
	i = 1;
	while (s[i] != '\0') { h += (s[i - 1] == s[i]) ? 5 : 10; i++;}
	printf("%d\n", h);	
	return 0;
}