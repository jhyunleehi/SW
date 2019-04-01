#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	int min = 0x7FFFFFFF;
	int N[4] = { 0, };
	int M[4] = { 0, };		
	int temp = 0;
	int cnt = 0;
	int k = 0;
	int map[10000] = { 0, };
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d %d", &N[0], &N[1], &N[2], &N[3]);

	for (int i = 0; i < 4; i++) {
		temp = (N[i % 4] * 1000) + (N[(i + 1) % 4] * 100) + (N[(i + 2) % 4] * 10) + (N[(i + 3) % 4]);	
		if (temp < min) min = temp;	
	}
	int stop = min;

	cnt = 0;
	for (int i = 1111; i <= 9999; i++) {
		temp = i;
		k = 0;
		min = 0x7FFFFFFF;
		for (int j = 1000; j >= 1; j = j / 10) {
			M[k] = temp / j;
			temp = temp - M[k++] * j;
		}
		for (int i = 0; i < 4; i++) {
			temp = (M[i % 4] * 1000) + (M[(i + 1) % 4] * 100) + (M[(i + 2) % 4] * 10) + (M[(i + 3) % 4]);			
			if (temp < min) min = temp;			
		}
		map[min] = 1;
	}

	for (int i = 1111; i < stop; i++) {
		if (map[i] != 0) {
			cnt++;
			//printf("%d: %d\n", i, cnt);
		}
	}
	printf("%d", cnt + 1);
}
