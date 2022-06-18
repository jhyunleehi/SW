#include <stdio.h>
int r, w, l, i=1;
int main() {
	freopen("data.txt", "r", stdin);
	while (1) {
		scanf("%d", &r);
		if (r == 0) break;
		scanf("%d %d", &w, &l);
		if ((2*r * 2*r) >= (w * w + l * l)) printf("Pizza %d fits on the table.\n", i);
		else  printf("Pizza %d does not fit on the table.\n", i);
		i++;
	}
	
	return 0;
}