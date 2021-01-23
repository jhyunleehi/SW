#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
unsigned char call(int in) {	
	if (in < 10) return in;
	int sum = 0;
	while (in >= 10) {
		sum += in % 10;
		in = in / 10;
	}
	sum += in;
	return call(sum);
}

int main() {
	freopen("data.txt", "r", stdin);
	int N = 10;
	int M[10 + 1] = { 0, };
	int in;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &in);
		M[call(in)]++;		
	}	
	int max = 0;	
	for (int i = 1; i <= N; i++) {		
		if (M[i] > max) {
			max = M[i];
			
		}
	}
	for (int i = 1; i <= N; i++) {
		if(M[i]==max)
			printf("%d ", i);	}
	printf("\n");
}
