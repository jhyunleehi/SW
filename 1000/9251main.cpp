
#include<stdio.h>

char a[1001], b[1001];
int  m[60][60], ans;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%s", a); scanf("%s", b);
	int lenb = 0, lena =0;
	while (a[lena] != '\0') lena++;
	while (b[lenb] != '\0') lenb++;
	for (int i = 1; i<= lena ; i++) {
		for (int j = 1; j<=lenb; j++) {
			if (a[i-1] == b[j-1]) 
				m[i][j] = m[i - 1][j - 1]+1;
			else 
				m[i][j] = (m[i][j - 1] > m[i - 1][j]) ? m[i][j - 1] : m[i - 1][j];
		}
	}
	printf("%d\n", m[lena][lenb]);
	return 0;
}