#include <stdio.h>
unsigned int a, ans,cnt;
unsigned int b = 0x80000000;
bool start;
int main() {
	scanf("%d", &a);
	for (int i = 0; i < 32; i++) {
		if (a & (b >> i)) 
			start = true;
		if (start) {
			if (a & (b >> i))	
				ans = ans  | (1<<cnt);
			cnt++;
		}
	}
	printf("%d", ans);
	return 0;
}