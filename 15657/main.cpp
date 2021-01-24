#include<stdio.h>
int N, M, m[9], a[9], temp;

void swap(int i, int j) {
	temp = m[i];
	m[i] = m[j];
	m[j] = temp;
}
void call(int s, int d) {
	a[d] = m[s];
	if (d == (M-1)) {
		for (int i = 0; i < M; i++) printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = s; i < N; i++) {
		call(i, d + 1);
	}	
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &m[i]);
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (m[i] > m[j]) swap(i, j);
		}
	}
	for (int i = 0; i < N; i++) call(i, 0);
	return 0;
}