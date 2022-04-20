#include <stdio.h>
int N,K,cnt;
int ans[12];
void call(int step, int sum) {	
	if (sum == N) {
		cnt++;
		if (cnt == K) { printf("%d", ans[0]); for (int k = 1; k < step ; k++) printf("+%d", ans[k]); printf("\n"); }
		return;
	}
	for (int i = 1; i <= 3 && K>cnt; i++) {
		if (sum + i <= N) ans[step] = i;
		else return;
		call(step + 1, sum+i);		
	}
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d",&N,&K);
	call(0,0); //step, sum
	if (cnt<K) printf("-1\n");
	return 0;
}