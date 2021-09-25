#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	float sum = 0;
	float in = 0.0;
	for (int i = 0; i < 12; i++) {
		scanf("%f", &in);
		sum += in;
	}
	printf("%.2f\n", sum / 12.0);
}
