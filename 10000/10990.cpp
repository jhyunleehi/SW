#include <stdio.h>
int N;
int main() {
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		for (int j = N; j > i; j--) printf(" ");
		printf("*");
		for (int j = 1; j < 2*(i-1) ; j++) printf(" "); 
		if (i != 1) printf("*\n");
		else printf("\n");
	}	
	return 0;
}