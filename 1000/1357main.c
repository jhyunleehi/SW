#include <stdio.h>
char str[6], out[6];
int a, b,c;

int revers(char* str) {
	int n = 0;
	int L= 0;
	while (*(str + L) != '\0') L++;
	for (int i = L-1; i >= 0; i--) {
		n = (n * 10) + *(str + i)-'0';
	}
	return n;
}
int  Revers(int n) {	
	int i = 0;
	while (n > 0) {
		a = n % 10;
		out[i++] = a + '0';
		n = n / 10;
	}
	out[i] = '\0';

	int ans = 0;
	int L = 0;
	while (*(out + L) != '\0') L++;
	for (int i = 0; i <L; i++) {
		ans = (ans * 10) + *(out + i) - '0';
	}
	return ans;
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%s", str);
	a = revers(str);
	scanf("%s", str);
	b= revers(str);
	printf("%d\n", Revers(a + b) );	
	return 0;
}