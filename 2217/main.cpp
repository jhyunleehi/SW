#include <stdio.h>
int n,m[100001],k,cnt;
long long max = 0;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		m[k]++;
	}	
	for (int i = 100000; i >= 1; i--) {
		if (m[i] != 0) {
			cnt+=m[i];
			max = (max < (i * cnt)) ? (i * cnt) : max;
		}		
	}
	printf("%lld\n", max);
	return 0;
}