#include<stdio.h>
#include<malloc.h>
int main() {
	char str[31];
	int  N = 0;
	freopen("data.txt", "r", stdin);
	scanf("%s", str);
	int i = 0;
	bool MINUS = false;
	if (str[i] == '1') {
		MINUS = true;
		while (str[i] != NULL) {
			str[i] = (str[i] == '0') ? '1' : '0';
			i++;
		}
	}
	i = 0;
	while (str[i] != NULL) {
		N = (N << 1) + str[i++] - '0';
	}
	if (MINUS) N = N*-1-1;
	printf("%d\n", N);
	return 1;
}
