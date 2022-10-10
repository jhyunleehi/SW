#include <stdio.h>
int a,b;
char str[1001];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&a);
	while (a--) {
		scanf("%s", str);
		b = 0;
		while (str[b] != '\0') b++;
		printf("%c%c\n", str[0], str[b - 1]);
	}	
	return 0;
}