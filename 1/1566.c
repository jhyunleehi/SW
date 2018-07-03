#include<stdio.h>
#include<malloc.h>
int isPrimeNumber(int n) {
	if (n <= 1) return 0;
	int last = n / 2;
	for (int i = 2; i <= last; i++) {
		if (n%i == 0) return 0;
	}
	return 1;
}

int main() {
	char ch;
	char str[10000 + 1];
	int i = 0;
	int DT[26] = { 0, };
	freopen("data.txt", "r", stdin);
	scanf("%s", str);
	while (*(str + i) != '\0') {
		DT[*(str + i) - 'A'] += 1;
		i++;
	}
	//for (int j = 0; j < 26; j++) printf("%c %d\n", j + 'A', DT[j]);
	int cnt = 0;
	for (int j = 0; j < 26; j++)
		if (isPrimeNumber(DT[j])) {
			printf("%c", j + 'A');
			cnt++;
		}
	if (cnt == 0) printf("NONE\n");
}
