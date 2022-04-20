#include<stdio.h>

int L, C;
char n[16], m[7];

bool chk() {
	int ms = 0, cs = 0;;
	for (int i = 0; i < L; i++) {
		if (m[i] == 'a' || m[i] == 'e' || m[i] == 'i' || m[i] == 'o' || m[i] == 'u')
			ms++;
		else
			cs++;
	}
	if (ms >= 1 && cs >= 2) return true;
	else return false;
}


void call(int k, int d) {
	m[d] = n[k];
	if (d == (L-1)) {
		if (chk()) {
			for (int i = 0; i < L; i++) 
				printf("%c", m[i]); printf("\n");
		}
		return;
	}
	for (int i = k+1; i < C; i++) {
		call(i, d + 1);
	}
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &L, &C);
	char ch = '\0';
	int i = 0;
	while ((ch = getchar()) != -1) {
		if (ch >= 'a' && ch <= 'z') n[i++]=ch;
	}
	//for (int i = 0; i < C; i++) scanf("%c", &n[i]);
	for (int i = 0; i < C - 1; i++) {
		for (int j = i; j < C; j++) {
			if (n[i] > n[j]) {
				char temp = n[i]; n[i] = n[j]; n[j] = temp;
			}
		}
	}
	for (int i = 0; i < C; i++) call(i, 0);
	return 0;
}