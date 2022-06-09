#include <stdio.h>
void change(int n)
{
	if (n == 0) return; 
	change(n / 2);      
	printf("%d", n % 2);
}

int main()
{
	int N;
	scanf("%d", &N);
	change(N);
	return 0;
}
