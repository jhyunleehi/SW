#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	int min = 0x7FFFFFFF;
	int N[4] = { 0, };
	int M[4] = { 0, };
	int temp = 0;
	int cnt = 0;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d %d", &N[0], &N[1], &N[2], &N[3]);
	for (int i = 0; i < 4; i++) {
		temp = (N[i % 4] * 1000) + (N[(i + 1) % 4] * 100) + (N[(i + 2) % 4] * 10) + (N[(i + 3) % 4]);
		if (temp < min) min = temp;
		//printf("min %d temp %d \n", min, temp);
	}
	int k = 0;
	for (int i = 1000; i >= 1; i=i/10) { 
		M[k] = min / i; 
		min = min - M[k++] * i;
	}
	//for (int i = 0; i < 4; i++) {printf("[%d] \n", M[i]);}
	
	k = 0;
	for (int i = 900; i >=1 ; i=i/10) {
		cnt+=(M[k++] - 1)*i;
	}
	cnt += M[3] - 1;	
	printf("%d\n", cnt);
}
