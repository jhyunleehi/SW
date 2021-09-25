#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>

char A[201], B[201], C[210], D[210];
char AR[201], BR[201];

void plus(char big[], int bs, char small[], int ss) {
	int up(0);
	int T(0);
	int i(0);
	int size(0);
	for (i = 0; i <= bs - 1; i++) {
		if (i < ss) T = small[i]; 
		else T = 0;
		if ((big[i] + T) >= 10) {
			big[i + 1]++;
			C[i] = (big[i] + T) - 10;
		}
		else	C[i] = (big[i] + T);
	}
	if (big[i-1] + T >= 10) {
		C[i] = 1;
		size = ++i;
	}
	else {
		size = i;
	}
	for (i = size - 1; i >= 0; i--) printf("%d", C[i]);	
	printf("\n");
}

void minus(char big[], int bs, char small[], int ss) {
	int i(0);
	int T(0);
	int size(0);
	for (i = 0; i <= bs - 1; i++) {
		if (i < ss) T = small[i]; 
		else T = 0;
		if ((big[i] - T) < 0 ) { 
			big[i + 1]--; 
			D[i] = (10 + big[i]) - T; }
		else { D[i] = big[i] - T; }
		
	}
	size = i;
	for (i = bs - 1; i >= 0; i--) {
		if (D[i] == 0) size--;
		else break;
	}
	for (i = size - 1; i >= 0; i--)  printf("%d", D[i]); 
	printf("\n");
}

int main() {
	freopen("Text.txt", "r", stdin);	
	int as(0), bs(0);
	while (!0) {
		scanf("%s", A);
		scanf("%s", B);
		as = 0, bs = 0;
		while (A[as] != '\0') as++;
		while (B[bs] != '\0') bs++;
		if (A[0] == '0'&& B[0] == '0') break;
		for (int i = as - 1; i >= 0; i--) AR[as-1-i] = A[i] - '0';
		for (int i = bs - 1; i >= 0; i--) BR[bs-1-i] = B[i] - '0';
		if (as > bs) plus(AR, as, BR, bs);
		else plus(BR, bs, AR, as);			

		for (int i = as - 1; i >= 0; i--) AR[as - 1 - i] = A[i] - '0';
		for (int i = bs - 1; i >= 0; i--) BR[bs - 1 - i] = B[i] - '0';		
		if (as > bs) minus(AR, as, BR, bs);
		else if (bs > as) minus(BR, bs, AR, as);
		else if (as == bs) {
			for (int i = as - 1; i >= 0; i--) {
				if (AR[i] > BR[i]) {
					minus(AR, as, BR, bs);
					break;
				}
				else if (AR[i] < BR[i]) {
					minus(BR, bs, AR, as);
					break;
				}
				if (i==0) printf("0\n");
			}
			
		}
	}
}
