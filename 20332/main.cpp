#include <stdio.h>
int n,p,sum;
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p);
		sum += p;
	}
	if ((sum % 3)==0) printf("yes");
	else  printf("no");
}