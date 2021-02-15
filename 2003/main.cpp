#include <stdio.h>
int n,m,N[10001];
int a, b,sum,cnt;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d",&n,&m);
	for (int i = 0; scanf("%d", &N[i]) != EOF; i++);
	sum = N[b];
	while (b <= n) {
		if (sum < m) { 
			b++; sum += N[b]; 
		}else if (sum == m) {
			cnt++;
			sum -= N[a]; a++;
		}else if (sum>m){
			sum -= N[a]; a++; 
		}
	}
	printf("%d\n", cnt);
	return 0;
}