#include<stdio.h>

char str[51];
int k;

int get_int() {
	int n = 0;
	char ch = NULL;
	while ((ch = str[k]) >= '0' && (ch <= '9')) {
		n = (n << 3) + (n << 1) + ch - '0';
		k++;
	}
	return n;
}

int st[51];
int top;

int a;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%s", str);
	a = get_int();
	st[++top] = a;
	while (str[k] != '\0') {
		if (str[k] == '+') {
			k++;
			a = get_int();
			st[top] = st[top] + a;
		}
		if (str[k] == '-'){
			k++;
			a = get_int();
			st[++top] = a;
		}
	}
	int ans = st[1];
	for (int i = 2; i <= top; i++) {
		ans -= st[i];
	}
	printf("%d\n", ans);
	return 0;
}