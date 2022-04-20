#include <stdio.h>
int a, b,maxa,maxb,mina,minb, max, min;
int getmax(int n) {
	int temp = n, rtn = 0;;
	for (int n = 1; temp != 0; n++) {
		int step = 1;
		for (int i = 1; i < n; i++) step = step * 10;
		if (temp % 10 == 5) rtn += 6 * step;
		else rtn += (temp % 10) * step;
		temp = temp / 10;
	}
	return rtn;
}
int getmin(int n) {
	int temp = n, rtn = 0;;
	for (int n = 1; temp != 0; n++) {
		int step = 1;
		for (int i = 1; i < n; i++) step = step * 10;
		if (temp % 10 == 6) rtn += 5 * step;
		else rtn += (temp % 10) * step;
		temp = temp / 10;
	}
	return rtn;
}

int main() {
	scanf("%d %d",&a, &b);
	int temp = a;
	maxa = getmax(a); maxb = getmax(b);
	mina = getmin(a); minb = getmin(b);	
	printf("%d\n", mina+minb);
	printf("%d\n", maxa + maxb);
	
	printf("\n");
	return 0;
}