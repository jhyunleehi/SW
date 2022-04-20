#include <stdio.h>
int n,m[31];
int main() {
	scanf("%d",&n);
	m[0] = 1;  m[1] = 0; m[2] = 3; m[3] = 0;
	for (int i = 4; i <= 30; i+=2) {
		if (i % 2 == 0) m[i] = m[i - 2] * 3;
		for (int j = 4; j <= i; j+=2) {
			m[i] = m[i] + m[i - j] * 2;
		}
	}	
	printf("%d\n", m[n]);	
	return 0;
}