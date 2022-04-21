#include <stdio.h>
int N;
char str1[1001], str2[1001];
int  C1[26], C2[26];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s", str1, str2);
		bool impossible = false;
		for (int i = 0; i < 26; i++) { C1[i] = 0; C2[i] = 0; }
		for (int i = 0; str1[i] != '\0'; i++) C1[(str1[i] - 'a')]++;
		for (int i = 0; str2[i] != '\0'; i++) C2[(str2[i] - 'a')]++;
		for (int i = 0; i < 26; i++) { 
			if (C1[i] != C2[i]) {
				impossible = true;
				break;
			}
		}
		if (impossible) printf("Impossible\n");
		else printf("Possible\n");
	}	
	return 0;
}