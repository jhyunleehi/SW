#include <stdio.h>
int N,M, S,a,b;
int minmap[2 << 5]; //17
int maxmap[2 << 5]; //17
int wmap[2 << 5];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d",&N, &M);
	int temp = N;
	while (temp /= 2) S++;
	int base = 2 << S;
	for (int i = 0; i < N; i++) {
		scanf("%d", &minmap[base + i]);
		wmap[base+i] = maxmap[base + i] = minmap[base + i];
	}
	int start = base/2, end = start * 2;
	while (start >= 1) {
		for (int i = start; i < end; i++) {
			minmap[i] = (minmap[i * 2] < minmap[i * 2 + 1]) ? minmap[i * 2] : minmap[i * 2 + 1];
			maxmap[i] = (maxmap[i * 2] > maxmap[i * 2 + 1]) ? maxmap[i * 2] : maxmap[i * 2 + 1];
		}
		start = start / 2, end = start * 2;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		start = base + a; end = base + b;
		while (start >= 1) {			
			if (start % 2 == 1) {
				wmap[start / 2] = wmap[start];
			}
			else {
				wmap[start / 2] = (wmap[start] < minmap[start + 1]) ? wmap[start] : minmap[start + 1];
			}
			if (end % 2 == 0) {
				wmap[end / 2] = wmap[end];
			}
			else {
				wmap[end / 2] = (wmap[end] < minmap[end - 1]) ? wmap[end] : minmap[start -1];
			}
			start = start / 2, end = start * 2;
		}
		printf("%d", wmap[1]);

		while (start >= 1) {
			if (start % 2 == 1) {
				wmap[start / 2] = wmap[start];
			}
			else {
				wmap[start / 2] = (wmap[start] > maxmap[start + 1]) ? wmap[start] : maxmap[start + 1];
			}
			if (end % 2 == 0) {
				wmap[end / 2] = wmap[end];
			}
			else {
				wmap[end / 2] = (wmap[end] > maxmap[end - 1]) ? wmap[end] : maxmap[start - 1];
			}
			start = start / 2, end = start * 2;
		}

		printf("%d", wmap[1]);
	}
}