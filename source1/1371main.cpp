#include <stdio.h>
int  cnt[26];
int maxcnt = 0;
int main() {
	freopen("data.txt", "r", stdin);
	char ch = 0;
	while ((ch = getchar()) != EOF) {
		if ((ch >= 'a') && (ch <= 'z')) {
			cnt[ch - 'a']++;
			maxcnt = (cnt[ch - 'a'] > maxcnt) ? cnt[ch - 'a'] : maxcnt;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == maxcnt) printf("%c", i + 'a');
	}
	printf("\n");
	return 0;
}