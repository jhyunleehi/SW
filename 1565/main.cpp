#include<stdio.h>

int n,m=1, temp;
int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 0; i < 28; i++) {
		scanf("%d", &n);
		m |=(1 << n) ;		
	}	
	for (int i = 0; i <= 30; i++) {
		if (!(m & (1<<i) )) 
			printf("%d\n", i );		
	}
	return 0;
}