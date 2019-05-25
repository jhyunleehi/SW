#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int A[3]; 
	scanf("%d %d %d", &A[0],&A[1],&A[2]);
	int cnt = 0;
	int temp;
	if (A[1] - A[0] > A[2] - A[1]) {
		A[2] = A[1];
		A[1] = A[0] + 1;
		if (A[0] < A[1] && A[1] < A[2]) cnt++;		
	}
	while (A[0] < A[1] && A[1] < A[2]) {		
		A[0] = A[1];
		A[1] = A[1] + 1;		
		if (A[0] < A[1] && A[1] < A[2]) cnt++;		
		A[0] = A[1];
		A[1] = A[2] - 1;		
		if (A[0] < A[1] && A[1] < A[2]) cnt++;		
		A[2] = A[1];
		A[1] = A[0] + 1;
		if (A[0] < A[1] && A[1] < A[2]) cnt++;
	}	
	printf("%d\n",cnt);		
}
