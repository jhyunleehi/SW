#include <stdio.h>
int a[4], b[4];
int n, m;
int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 0; i < 4; i++){
		scanf("%d", &a[i]);
		n += a[i];
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &b[i]);
		m += b[i];
	}	
	printf("%d\n", n > m ? n : m);
	return 0;
}