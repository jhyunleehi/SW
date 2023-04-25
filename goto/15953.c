#include <stdio.h>
int M2017[7] = { 0,500,300,200,50,30,10 };
int M2018[6] = { 0,512,256,128,64,32 };
int N, a, b, ans;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &a, &b);
		ans = 0;
		int rank = 0;
		for (int i = 1; i <= 6; i++) {
			rank += i;
			if (a == 0) break;
			if (a <= rank) {
				ans += M2017[i];
				break;
			}
		}
		rank = 1;
		int step = 1;
		for (int i = 1; i <= 5; i++) {
			printf("[%d][%d]\n", i, rank);
			if (b == 0) break;
			if (b <= rank) {
				ans += M2018[i];
				break;
			}
			step *= 2;
			rank += step;
		}
		printf("%d\n", ans * 10000);
	}
	return 0;
}