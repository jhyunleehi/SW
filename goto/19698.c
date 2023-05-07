#include <stdio.h>
int N, W, H, L,ans;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d", &N, &W, &H, &L);
	ans = N < ((W / L) * (H / L)) ? N : ((W / L) * (H / L));
	printf("%d\n", ans);
}