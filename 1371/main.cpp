#include <stdio.h>
char buf[1 << 8];
int  cnt[26][2];
inline char read() {
	static int idx = 1 << 8;
	static int len = 0;
	if (idx == 1 << 8) {
		len = fread(buf, 1, 1 << 8, stdin);		
		//printf("[%d]\n", len);
		idx = 0;		
	}
	if (idx >= len) return '\0';
	return buf[idx++];
}
void swap(int p, int q) {
	int temp1 = cnt[p][0], temp2 = cnt[p][1];
	cnt[p][0] = cnt[q][0]; cnt[p][1] = cnt[q][1];
	cnt[q][0] = temp1; cnt[q][1] = temp2;
}

void qsort(int L, int R) {
	int p = L, q = R, v = cnt[(L + R) / 2][0];
	while (p <= q) {
		while (cnt[p][0] > v) p++;
		while (cnt[q][0] < v) q--;
		if (p <= q) {
			if (cnt[p][0] < cnt[q][0]) {
				swap(p, q);				
			}
			if ((cnt[p][0] == cnt[q][0]) && (cnt[p][1] > cnt[q][1])) {
				swap(p, q);				
			}
			p++; q--;
		}
	}
	if (q > L) qsort(L, q);
	if (p < R)qsort(p, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	int n=0;
	while ((n = read()) != '\0') {
		if ((n >= 'a') && (n <= 'z')) {
			cnt[n - 'a'][0]++;
		}
	}
	for (int i = 0; i < 26; i++) cnt[i][1] = i;
	qsort(0, 25);
	int key = cnt[0][0], i = 0;
	while ((cnt[i][0] == key)&&(i<26)) {
		printf("%c", cnt[i][1] + 'a');
		i++;
	}
	printf("\n");	
	return 0;
}