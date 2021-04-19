#include <stdio.h>
int  n, h[100002], k;
int st[100002], top;
long long max, ar1, ar2,w1,w2;

void push(int n) {
	st[++top] = n;
}
void pop() {
	if (top >= 1) {
		st[top--] = -1;
	}
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)  scanf("%d", &h[i]);

	for (int i = 0; i < n ; i++) {		
		while ((h[i] <  h[st[top]]) && (top >= 1)) {
			k = st[top];
			pop(); 
			if (top >=1) 
				w1 = i - (st[top]+1 ); 
			else 	
				w1 = i;			
			ar1 = h[k] * w1; 									
			max = (max < ar1) ? ar1 : max;			
		}
		push(i);
	}
	while (top >= 1) {
		k = st[top];
		pop();
		if (top >= 1)
			w1 = n - (st[top] + 1);
		else
			w1 = n;
		ar1 = h[k] * w1;
		max = (max < ar1) ? ar1 : max;
	}
	printf("%d\n", max);
	return 0;
}