#include <stdio.h>
int n,m,g,cnt;
int v, f, c;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	while (n--) {
		scanf("%d %d", &m, &g);
		cnt = 0;
		while (m--) {
			scanf("%d %d %d", &v, &f, &c);
			if (g <= (v * f / (c*1.0)))
				cnt++;
		}
		printf("%d\n", cnt);
	}	
	return 0;
}