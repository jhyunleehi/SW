#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int N; 
	scanf("%d", &N);
	for (int i = N; i >= 1; i--) {
		for (int k = 0; k < N - i; k++) printf(" ");
		for (int j = i; j >= 1; j--) printf("%d", j);
		printf("\n");	
	}
}
