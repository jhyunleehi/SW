#include <stdio.h>
int a[3],temp,cnt;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d",&a[0], &a[1], &a[2]);
	while (a[0] != a[1] && a[1] != a[2]) {
		if ((a[1] - a[0]) < (a[2] - a[1])) {
			temp = a[1]; a[1] = a[1] + 1; a[0] = temp;
		}
		else {
			temp = a[1]; a[1] = a[1] - 1; a[2] = temp;
		}
		cnt++;
	}
	printf("%d\n", cnt-1);
	return 0;
}