#include <stdio.h>
int K, D, A;
int main() {
	scanf("%d/%d/%d",&K,&D,&A);
	if ((K+A)<D || D==0) printf("hasu");
	else  printf("gosu");
}