#include <stdio.h>
int a, b;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &a);
	while (1) {		
		scanf("%d", &b);
		if (b == 0) break;
		if (b%a==0) 
			printf("%d is a multiple of %d.\n", b, a);
		else 
			printf("%d is NOT a multiple of %d.\n", b, a);
	}	
	return 0;
}