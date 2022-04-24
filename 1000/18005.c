#include <stdio.h>
int N;
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);	
	if(N % 4 == 0) printf("2");
	else if (N % 4 == 2) printf("1");
	else printf("0");
}