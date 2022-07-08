#include<stdio.h>
char ch,cnt;
int main() {
	freopen("data.txt", "r", stdin);
	while ((ch = getchar()) != -1) 
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') cnt++;
	printf("%d\n", cnt);
}
