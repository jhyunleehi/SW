#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
char str[100];
int m[26];

int main() {
	//freopen("data.txt", "r", stdin);
	scanf("%s", str);
	memset(m, -1, 26*4);
	for (int i = 0; str[i] != '\0'; i++) {
		int c = str[i] - 'a';
		if (m[c] == -1) m[c] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", m[i]);
	}
	return 0;
}