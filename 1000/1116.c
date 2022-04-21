#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int N = 9;
	int max = 0x7FFFFFFF + 1;
	int in,row,col;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &in);
			if (max < in) {
				max = in;
				row = i;
				col = j;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d\n", row, col);

}
