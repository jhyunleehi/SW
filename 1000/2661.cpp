#include <stdio.h>
int N;
int m[81];

bool chkGood(int n) {
	if (n<1) return true;
	//for (int i = 0; i < N; i++) printf("%d", m[i]);	printf("\n");	
	int bad = 0;
	int idx = 1;
	for (int i = n; i > (n / 2); i--) {
		int a = n, b = n-(idx);
		int k = 0;
		for (int j = 0; j < idx; j++) {
			if ((a - j) >= 0 && (b - j) >= 0) {
 				if (m[a - j] == m[b - j]) continue;
				else { k = 1; break; }
			}
		}
		idx++;
		if (k == 0) bad = 1;
	}
	if (bad == 1) return false;
	else return  true;
}
bool find;
void call(int n) {	
	if (n == N) {
		find = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		m[n] = i;
		if (chkGood(n)) {
			call(n + 1);			
			if (find) return;
		}
	}
}
int main() {
	scanf("%d", &N);
	call(0);
	for (int i = 0; i < N; i++) printf("%d", m[i]);
	printf("\n");
	return 0;
}