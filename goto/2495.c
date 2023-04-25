#include <stdio.h>
char str[9];
int main() {
	freopen("data.txt", "r", stdin);
	int n = 3;
	while (n--) {
		scanf("%s", str);
		int ans = 0,cnt=1;
		for (int i = 0; i < 7; i++) {
			if (str[i] == str[i + 1]) cnt++;
			else cnt = 10;
			ans = (ans < cnt) ? cnt : ans;
		}
		printf("%d\n", ans);		
	}	
	return 0;
}