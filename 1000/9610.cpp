#include <stdio.h>
int n,y,x, q[5],axis;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	while (n--) {
		scanf("%d %d", &x, &y);
		if (x == 0 || y == 0) axis++;
		if (x > 0 && y > 0) q[1]++;
		if (x < 0 && y > 0) q[2]++;
		if (x < 0 && y < 0) q[3]++;
		if (x > 0 && y < 0) q[4]++;
	}
	for (int i = 1; i <= 4; i++) {
		printf("Q%d: %d\n", i, q[i]);
	}
	printf("AXIS: %d\n", axis);	
	return 0;
}
