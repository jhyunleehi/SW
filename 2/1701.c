#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	char* str;
	int N = 0;
	str = (char*)malloc(sizeof(char) * 501);
	int *M = (int *)malloc(sizeof(int) * 501);
	freopen("data.txt", "r", stdin);
	scanf("%s", str);
	while (*(str + N) != NULL) N++;
	for (int i = 0; i < N; i++) *(M + i) = 0;
	//printf("%d", N);

	for (int i = 1; i < N; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (*(M + j) != 0) {
				continue;
			} else if (*(str + i) == 't' && *(str + j) == 'a'){
				*(M + i) = (i - j) + 1;
				*(M + j) = (i - j) + 1;
				break;
			} else if  (*(str + i) == 'c' && *(str + j) == 'g') {
				*(M + i) = (i - j) + 1;
				*(M + j) = (i - j) + 1;
				break;
			}
			else if (*(M + j) == 0) {
				break;
			}
		}
		//for (int k = 0; k < N; k++) printf("[%d]", *(M + k)); printf("\n");
	}
	int ans = 0;
	int i = 0;
	int s = 0;
	while(i<N){
		if (*(M + i) != 0) {
			if (ans < ((i - s) + 1)) ans = (i - s) + 1;
		}
		if (*(M + i) == 0) {		
			s = i+1;
		}		
		i++;
	}
	printf("%d\n", ans);

}
