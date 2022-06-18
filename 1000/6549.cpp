#include <stdio.h>
long long n, m[100001];
long long max, area;
int  s[100001], top;
void push(int n) {
	s[++top] = n;
}
void pop() {
	if (top < 1) return;
	s[top] = -1;
	top--;
}
int main() {
	freopen("data.txt", "r", stdin);
	while (1) {
		scanf("%d", &n);
		if (n == 0)return 0;
		for (int i = 1; i <= n; i++) scanf("%d", &m[i]);
		m[n + 1] = 0;
		max = 0; top = 0;
		for (int i = 1; i <= n + 1; i++) {
			while ((m[i] < m[s[top]]) && (top > 0)) {
				int t = s[top];
				pop();
				if (top >= 1)  area = m[t] * (i - (s[top] + 1));
				else area = m[t] * (i - 1);
				max = (max < area) ? area : max;
			}
			push(i);
		}
		while (top > 0) {
			int t = s[top];
			pop();
			if (top >= 1) area = m[t] * (n - (s[top] + 1));
			else  area = m[t] * n;
			max = (max < area) ? area : max;
		}
		printf("%lld\n", max);
	}

	return 0;
}