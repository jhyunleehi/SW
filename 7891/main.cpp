#include <stdio.h>
int a, b;
int main() {	
		scanf("%d %d", &a, &b);
		if (a <= 50 && b <= 10) printf("White");
		else if (b >= 30) printf("Red");
		else printf("Yellow");
		printf("\n");		
	return 0;
}