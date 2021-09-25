#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {	
	int a, b, c;
	int max = 0x7fffffff + 1;
	int result;
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &a, &b, &c);
	int *cnt = (int*)malloc(sizeof(int)*(a + b + c + 1));
	for (int i = 0; i <= a + b + c; i++) {
		*(cnt + i) = 0;
	}	
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				*(cnt + i + j + k)= *(cnt + i + j + k)+1;
				if (max < *(cnt + i + j + k)) {
					max = *(cnt + i + j + k);
					result = i + j + k;
				}
					
			}
		}
	}
	printf("%d\n", result);	
}
