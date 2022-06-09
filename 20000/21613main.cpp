#include <stdio.h>
int N,P;
int main() {
	scanf("%d",&N);
	P = (5 * N) - 400;
	printf("%d\n", P);
	if (P < 100) printf("1");
	else if (P == 100) printf("0");
	else printf("-1");	
}