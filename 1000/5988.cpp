#include <stdio.h>
int N;
char K[61];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	while (N--) {
		scanf("%s", K);
		int i = 0;
		while (*(K + i) != '\0')i++;
		if ((*(K + i - 1) - '0') & 1)
			printf("odd\n");
		else
			printf("even\n");
	}
	return 0;
}