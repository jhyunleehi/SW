#include <stdio.h>

char str[15];
int ans;
int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 1; i <= 5; ++i) {
		//fgets(str, sizeof(str), stdin);
		scanf("%s", str);
		printf("[%s]", str);
		for (int j = 0; str[j]; ++j) {
			if ((str[j] == 'F') && (str[j+1] == 'B')&&(str[j+2] == 'I')) {
				printf("%d ", i);
				ans++;
				break;
			}
		}
	}
	if (ans == 0) {
		printf("HE GOT AWAY!\n");
	}
}