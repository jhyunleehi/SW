#include <stdio.h>
int a;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&a);
	if (a % 2) printf("SK\n");
	else  printf("CY\n");
	return 0;
}