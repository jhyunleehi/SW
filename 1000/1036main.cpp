#include<stdio.h>
#include<algorithm>

char c36[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
int N, K;
int size[51], n36[51][56], com[36][56], toz[36], tozcnt, sum[56];

struct Base36 { int c, d[52]; } base[36];

void Mul(Base36& r, const Base36& a, int m) {
	for (int i = 0, c = 0; i < 52; i++) {
		r.d[i] = a.d[i] * m + c;
		c = r.d[i] / 36;
		r.d[i] %= 36;
	}
}
bool cmp(int a, int b) {
	Base36 ta, tb; Mul(ta, base[a], 35 - base[a].c);
	Mul(tb, base[b], 35 - base[b].c);
	for (int i = 51; i >= 0; i--) {
		if (ta.d[i] > tb.d[i]) return true;
		if (ta.d[i] < tb.d[i]) return false;
	}
	return false;
}

int get_str_len(char* str) {
	int i = 0;
	while (*(str + i) != '\0') i++;
	return i;
}


int main() {
	freopen("data.txt", "r", stdin);
	int i, j, t, c, idx[36];
	//for (int i = 0; i < 36; i++) for (int j = 0; j < 52; j++) { n36[i][j] = 0; com[i][j] = 0; }
	for (int i = 0; i < 36; i++) base[i].c = i, idx[i] = i;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		char s[56], str[56]; scanf("%s", str);
		size[n] = get_str_len(str);
		//for (int k = 0; s[k]; k++) s[k] = (s[k] < 'A') ? s[k] - '0' : s[k] - 'A' + 10;
		for (int k = 0; k < size[n]; k++) s[k] = (str[k] < 'A') ? str[k] - '0' : str[k] - 'A' + 10;
		for (int k = 0; k < size[n]; k++) n36[n][(size[n] - 1) - k] = s[k];
		for (int k = 0; k < size[n]; k++) com[n36[n][k]][k] ++;
		for (int t = 0, i = size[n] - 1; i >= 0; i--, t++) base[s[i]].d[t]++;
	}

	for (int d = 0; d < 36; d++) for (int i = 0; i < 52; i++) {
		com[d][i] = com[d][i] * (35 - d);
	}

	for (int d = 0; d < 36; d++) for (int i = 0; i < 52; i++) {
		if (com[d][i] >= 36) {
			com[d][i + 1] = com[d][i] / 36;
			com[d][i] = com[d][i] % 36;
		}
	}

	scanf("%d", &K);
	/*
	std::sort(idx, idx + 35, cmp);
	for (i = 0; i < K; i++) {
		toz[idx[i]] = 1;
		base[idx[i]].c = 35;
	}
	
	for (i = 0, c = 0; i < 52; i++) {
		for (j = 0, t = c; j < 36; j++)
			t += base[j].c * base[j].d[i];
		sum[i] = t % 36;
		c = t / 36;
	}
	*/

	bool begin = false;
	/*
	for (int i = 51; i >= 0; i--) {
		if ((sum[i] >= 1) || (i == 0)) begin = true;
		if (begin == true) {
			printf("%c", c36[sum[i]]);
		}
	}
	putchar('\n');
	*/


	if (K != 0) {
		for (int i = 52; i >=0; i--) {
			int temp = 0, select = -1;
			for (int d = 0; d < 36; d++) {
				if ((com[d][i] > temp) && (toz[d] == 0)) {
					temp = com[d][i];
					select = d;
				}
			}
			if (select != -1) {
				toz[select] = 1;
				tozcnt++;
				i = i + 1;
			}
			if (tozcnt >= K) break;
		}
	}
	

	for (int i = 0; i < 36; i++) {
		if (toz[i] == 1) {
			for (int n = 0; n < N; n++) {
				for (int j = 0; j < size[n]; j++) {
					if (n36[n][j] == i) n36[n][j] = 35;
				}
			}
		}
	}

	for (int i = 0; i < 52; i++) {
		for (int n = 0; n < N; n++) {
			sum[i] += n36[n][i];
		}
		if (sum[i] >= 36) {
			sum[i + 1] = sum[i] / 36;
			sum[i] = sum[i] % 36;
		}
	}


	begin = false;
	for (int i = 51; i >= 0; i--) {
		if ((sum[i] >= 1) || (i == 0)) begin = true;
		if (begin == true) {
			printf("%c", c36[sum[i]]);
		}
	}
	putchar('\n');
}