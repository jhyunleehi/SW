#include <stdio.h>
int T;
long long ans1,ans2,ans,a,b,c;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&T);
	while (T--) {
		scanf("%lld %lld", &a, &b);
		ans1 = 0;
		ans2 = 0;
		c = (a - b)-1;
		ans1 = ((a * 2) * (a + 1));
		ans2 = ((c * 2) * (c + 1));
		ans = ((a * 2) * (a + 1)) - ((c * 2) * (c + 1));		
		printf("%lld\n", ans);
	}	
	return 0;
}