#include <stdio.h>
int A[50001], B[50001], C[100001];
int alen, blen;
void update(int n) {
	for (int i = n; (i > 0)&&((n-i)<=blen); i--) {
		if (C[i] >= 10) {
			C[i - 1] += C[i] / 10;
			C[i] %= 10;
		}
	}
}

void printnum(int a[], int len) {
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i]) k = 1;
		if (k)	printf("%d", a[i]);
	}
    if (k==0) printf("0"); 
	printf("\n");
}

int main() {
	//freopen("data.txt", "r", stdin);
    int a,b;
    scanf("%d%d",&a,&b);
	char str[300001];
	scanf("%s",str);
	while (*(str + alen) != '\0') {
		A[alen] = *(str + alen) - '0';
		alen++;
	}
	scanf("%s", str);
	while (*(str + blen) != '\0') {
		B[blen] = *(str + blen) - '0';
		blen++;
	}
	//printnum(A, alen); 
	//printnum(B, blen);
	int idx = (alen + blen) - 1;
	for (int i = alen - 1; i >= 0; i--) {
		for (int j = blen - 1, k=0; j >= 0; j--, k++) {
			C[idx-k] += A[i] * B[j];
			if (C[idx - k] >= 10) {
				C[(idx - k) - 1] += C[(idx - k)] / 10;
				C[(idx - k)] %= 10;
			}
		}		
		idx--;
	}
	printnum(C, alen + blen);
	return 0;
}