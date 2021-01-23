#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int X, Y;
	int N;
	int S1[100] = { 0, };
	int S2[100] = { 0, };
	int H1, H2;
	int direction[5] = { 0,4,3,1,2 };
	scanf("%d %d", &X, &Y);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &S1[i],&S2[i]);
	}
	scanf("%d %d", &H1, &H2);

	for (int i = 0; i < N; i++) {
		if (S1[i] == 2) S2[i] = X - S2[i];		
		if (S1[i] == 3) S2[i] = Y - S2[i];
	}
	if (H1 == 2) H2 = X - H2;
	if (H1 == 3) H2 = Y - H2;

	int max = (X * 2 + Y * 2) / 2;
	int sum = 0;
	int cnt = 0;
	int side = 0;
	for (int k = 0; k < N; k++){
		cnt = 0;
		side = S1[k];
		if (H1 == side){
			cnt = (H2 > S2[k]) ? H2 - S2[k] : S2[k] - H2;
			if (cnt > max) cnt = max * 2 - cnt;
			//printf("%d %d  %d %d : [%d]\n", X, Y, S1[k], S2[k], cnt);
			sum += cnt;
			continue;
		}
		else {
			if ((side == 1) || (side == 2)) cnt = X - S2[k];
			if ((side == 3) || (side == 4)) cnt = Y - S2[k];			
			for (int i = 0; i < 3; i++) {
				side = direction[side];
				if ((H1 == side)){
					//cnt += (H2 > S2[k]) ? H2 - S2[k] : S2[k] - H2;
					cnt += H2;
					break;
				} else {
					if ((side == 3) || (side == 4)) cnt += Y;
					if ((side == 1) || (side == 2)) cnt += X;
				}
			}
		}				
		if (cnt > max) cnt = max*2 - cnt;
		//printf("%d %d  %d %d : [%d]\n", X, Y, S1[k], S2[k], cnt);
		sum += cnt;
	}
	printf("%d\n", sum);	
}
