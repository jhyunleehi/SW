#include <stdio.h>
int n[1001], m[1001], ans[1001];
int nlen = 0, mlen=0, idx=0;

int getdown(int i) {
	if (i < idx) return 0;
	if (n[i] >= 1) {
		n[i]--;				
	}
	else {
		if (getdown(i - 1) == 0) return 0;
		else n[i] = 9;
	}
	return 10;
}

int minus() {
	if (n[idx - 1]) {
		n[idx] = n[idx] + 10* n[idx - 1];
		n[idx - 1] = 0;
	}
	for (int i = (idx + mlen - 1), j=(mlen-1); (i >= idx)&&(j>=0);  i--, j--) {
		if (n[i] >= m[j]) {
			n[i] = n[i] - m[j];
		}
		else {
			if (getdown(i - 1)==0) return 0;
			n[i] = n[i] + 10 - m[j];
		}
	}
	return 1;
}

bool check_nm() {
	for (int i = 0; i < idx; i++) {
		if (n[i] > 0) return true;
		else continue;
	}
	for (int i = idx, j=0; (i < nlen)&&(j<mlen); i++, j++) {
		if (n[i] > m[j]) return true;
		else if (n[i] < m[j]) return false;
		else continue;
	}
	return true;
}

void printn() {
	for (int i = 0; i < nlen; i++) {
		printf("%d", n[i]);
	}
	printf("\n");
}

void printm() {
	for (int i = 0; i < mlen; i++) {
		printf("%d", m[i]);
	}
	printf("\n");
}
void printans() {
	int key = 0;
	for (int i = 0; i <= (nlen - mlen); i++) {
		if (ans[i]) key = 1;
		if (key) printf("%d", ans[i]);
	}
	printf("\n");
}

void printres() {
	int key = 0;
	for (int i = 0; i < (nlen); i++) {
		if (n[i]) key = 1;
		if (key) printf("%d", n[i]);
	}
	if (key == 0) printf("%d", 0);
	printf("\n");
}


void div() {
	for (idx = 0; idx <= (nlen-mlen); idx++) {
		while (check_nm()) {
			minus();
			ans[idx]++;
			//printans();
		}
	}
}



int main() {
	freopen("data.txt", "r", stdin);
	char str[1002];
	scanf("%s",&str);
	while (*(str + nlen) != '\0') {
		n[nlen] = str[nlen] - '0';
		nlen++;
	}	
	scanf("%s", &str);	
	while (*(str + mlen) != '\0') {
		m[mlen] = str[mlen] - '0';
		mlen++;
	}
		
	div();	
	printans();
	printres();
	
}