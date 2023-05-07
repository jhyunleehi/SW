#include <stdio.h>
int h, m, s, d;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d",&h,&m,&s,&d);
	int temp = h * 3600 + m * 60 + s + d;
	h = temp / 3600;
	m = (temp - (h * 3600)) / 60;
	s = (temp - (h * 3600) - (m * 60));
	printf("%d %d %d\n", h%24, m, s);
	return 0;
}