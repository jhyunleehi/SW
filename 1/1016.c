#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int N;
	int *list;
	int *map;
	int C[4] = { 0, };
	int count = 0;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	list = (int*)malloc(sizeof(int)*N + 1);
	map = (int*)malloc(sizeof(int)*N + 1);
	for (int i = 0; i < N; i++)
		scanf("%d", (list + i));
	for (int i = 0; i < N; i++) {
		C[*(list + i)]++;
	}
	int c = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < C[i]; j++) {
			*(map + c) = i;
			c++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (*(map + i) != *(list + i)) {
			for (int k = 0; k < N; k++) {
				if ((*(list + i) == *(map + k)) && (*(list + k) == *(map + i))) {					
					swap((list + i), (list + k));
					count++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (*(map + i) != *(list + i)) {
			for (int k = i + 1; k < N; k++) {
				if ((*(map + i) == *(list + k))&&(*(map + k) != *(list + k))) {										
					swap((list + i), (list + k));
					count++;
					break;
				}
			}
		}
	}
	printf("%d\n", count);
}
