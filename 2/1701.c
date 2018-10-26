#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	char* str;
	int N = 0;
	str = (char*)malloc(sizeof(char) * 501);	
	freopen("data.txt", "r", stdin);
	scanf("%s", str);
	while (*(str + N) != NULL) N++;
	int **DM = (int**)malloc(sizeof(int*)*N + 1);
	for (int i = 0; i < N; i++) *(DM + i) = (int*)malloc(sizeof(int)*N + 1);
	for (int i = 0; i < N; i++)	for(int j=0; j<N; j++)	*(*(DM + i)+j) = 0;
	
	//*(*(DM + j) + i) j에서 i까지에서 연속된 최대값
	int max = 0;
	int ans = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i-1; j >=0; j--) {
			if ( ((*(str + j) == 'a')&&(*(str + i) == 't'))  ||
				 ((*(str + j) == 'g') && (*(str + i) == 'c')) )
			{
				*(*(DM + j) + i) = *(*(DM + j + 1) + i - 1) + 2;
			}
			max = 0;
			for (int k = j ; k <= i - 1; k++) {
				int a = *(*(DM+j)+k);
				int b = *(*(DM + (k+1)) + i);
				max = (a+b > max) ? a+b : max;
			}
			*(*(DM + j) + i) = (max > *(*(DM + j) + i)) ? max : *(*(DM + j) + i);
			ans = (*(*(DM + j) + i) > ans) ? *(*(DM + j) + i) : ans;
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				printf("[%d]", *(*(DM + i) + j));
			printf("\n");
		}	
		printf("------------------------\n");
		*/
		
	}	
	printf("%d\n", ans);
}
