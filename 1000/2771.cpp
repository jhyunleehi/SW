#include <stdio.h>
int t, n;
char str[81];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%s", str);
		int i = 0;
		while (str[i] != '\0') {
			if ((i + 1) != n) printf("%c", str[i]);
			i++;			
		}
		printf("\n");
	}	
	return 0;
}