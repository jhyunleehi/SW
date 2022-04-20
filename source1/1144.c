#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int X, Y;
	char str[100 + 1];
	scanf("%d %d", &X, &Y);
	scanf("%s", str);
	int i = 0;
	while (str[i] != '\0') {
		switch (str[i]) {
		case 'U':
			Y++;
			break;
		case 'D':
			Y--;
			break;
		case 'L':
			X--;
			break;
		case 'R':
			X++;
			break;
		}
		i++;
	}
	printf("%d %d\n", X, Y);

}
