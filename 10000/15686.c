#include <stdio.h>
int N, M,k;
int C[14][2], ccnt, visit[14],str[14]; //y,x 
int H[51 * 2][2], hcnt; //y,x
int ch[14][51*2]; //chicken * home
int dist[51*2], ans=0x7fffffff;    //H<=2N(50), M <=13

void countlen(int a, int b) {
	int t1 = C[a][0] - H[b][0];
	int t2 = C[a][1] - H[b][1];
	t1 = (t1 > 0) ? t1 : t1 * -1;
	t2 = (t2 > 0) ? t2 : t2 * -1;
	ch[a][b] = t1 + t2;
}

void call(int m, int cnt) {
	visit[m] = 1;
	str[cnt-1] = m;
	if (cnt == M) {
		//for (int i = 0; i < M; i++) printf("%d ", str[i]);
		for (int i = 0; i < hcnt; i++) dist[i] = 0x7FFFFFFF;		
		for (int i = 0; i < M; i++) {
			for (int h = 0; h < hcnt; h++) {				
				if (dist[h] > ch[str[i]][h]) {
					dist[h] = ch[str[i]][h];
				}
			}
		}
		int temp = 0;
		for (int h = 0; h < hcnt; h++) temp += dist[h];		
		if (ans > temp) ans = temp;
		//printf(" ans:%d temp: %d\n", ans, temp);
		return;
	}
	for (int i = m + 1; i < ccnt; i++) {
		if (visit[i] == 0) {
			call(i, cnt + 1);
			visit[i] = 0;
		}
	}
}

int main() {	
	freopen("data.txt", "r", stdin);
	scanf("%d %d",&N,&M);
	for (int y = 1; y <= N; y++) 	{
		for (int x = 1; x <= N; x++) {
			scanf("%d", &k);
			if (k == 2) {	C[ccnt][0] = y,	C[ccnt][1] = x, ccnt++;		}
			if (k == 1) {	H[hcnt][0] = y, H[hcnt][1] = x, hcnt++;	}
		}
	}
	for (int c=0; c < ccnt; c++) {
		for (int h = 0; h < hcnt; h++) {
			countlen(c, h);
		}
	}
	for (int m = 0; m < ccnt; m++) {
		call(m,1);
		visit[m] = 0;
	}

	printf("%d\n", ans);
	return 0;
}