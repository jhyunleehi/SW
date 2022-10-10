#include <stdio.h>
char A[2100], B[2100], C[5000];
int  lena, lenb;

void fix(char* str) {
	if (*str == '-') return;
	else {
		char temp1 = 0, temp2 = *str;
		int idx = 0;
		while (1) {
			temp1 = *(str + idx);
			*(str + idx) = temp2;
			temp2 = temp1;
			if (*(str + idx) == '\0') break;
			idx++;
		}
		*str = '+';
	}
}

int strlen(char* str) {
	int idx = 0;
	while (*(str + idx) != '\0') idx++;
	return idx;
}
int strcomp(char* p, char* q) {
	int i = 1;
	while (*(p + i) && *(p + i) == *(q + i)) i++;
	return  *(p + i) - *(q + i);
}
void strcopy(char* p, char* q) {
	while ((*(q++) = *(p++)) != '\0');
}
void arrage(char* A, char* B) {
	int lena = strlen(A);
	int lenb = strlen(B);
	char buffer[2100];
	char* temp = buffer;
	if (lenb > lena) {
		strcopy(A, temp);
		strcopy(B, A);
		strcopy(temp, B);
	}
	else if (lena == lenb) {
		if (strcomp(A, B) == -1) {
			strcopy(A, temp);
			strcopy(B, A);
			strcopy(temp, B);
		}
	}
}
void fixp(char* p) {
	char buffer[2100];
	strcopy(p, buffer);
	int len = strlen(p);
	for (int i = len - 1, j = 1; i > 0; i--, j++) {
		*(p + j) = buffer[i];
	}
}
void padd(char* p, char* q, char* c) {
	int psz = strlen(p);
	int qsz = strlen(q);
	int temp[2100] = { 0, };
	for (int i = 1; i < psz; i++) temp[i] = *(p + i) - '0';
	for (int i = 1; i < qsz; i++) {
		temp[i] += (*(q + i) - '0');
	}
	for (int i = 1; i <= (psz + qsz); i++) {
		if (temp[i] > 9) {
			temp[i + 1] += temp[i] / 10;
			temp[i] = temp[i] % 10;
		}
	}
	for (int i = 1; i <= (psz + qsz); i++) {
		*(c + i) = temp[i] + '0';
	}
}

void psub(char* p, char* q, char* c) {
	int psz = strlen(p);
	int qsz = strlen(q);
	int temp[2100] = { 0, };
	for (int i = 1; i < psz; i++) temp[i] = *(p + i) - '0';
	for (int i = 1; i < qsz; i++) {
		temp[i] -= (*(q + i) - '0');
	}
	for (int i = 1; i <= (psz + qsz); i++) {
		if (temp[i] < 0) {
			temp[i + 1] = temp[i + 1] - 1;
			temp[i] = temp[i] + 10;
		}
	}
	for (int i = 1; i <= (psz + qsz); i++) {
		*(c + i) = temp[i] + '0';
	}
}

void printans(char* c, int msz) {
	int lenc = 0;
	for (int i = msz; i > 0; i--) {
		if (*(c + i) != '0') {
			lenc = i;
			break;
		}
	}
	if (lenc == 0) {
		printf("0\n");
		return;
	}
	if (*c == '-') printf("-");
	for (int i = lenc; i > 0; i--) printf("%c", *(c + i));
	printf("\n");
}



void add(char* p, char* q, char* c) {
	int psz = strlen(p);
	int qsz = strlen(q);
	int msz = psz + qsz;
	if (*(p) == *(q)) {
		padd(p, q, c);
	}
	if (*(p) != *(q)) {
		psub(p, q, c);
	}
	if (*(p) == '-') *(c) = '-';
	else *(c) = '+';

	//printf("[%s][%s][%s]\n", p, q, c);
	printans(c, msz);
}


void mul(char* p, char* q, char* c) {
	int psz = strlen(p);
	int qsz = strlen(q);
	int msz = psz + qsz;
	int temp[5000] = { 0, };
	for (int i = 1; i < qsz; i++) {
		for (int j = 1; j < psz; j++) {
			temp[i + j - 1] += (*(p + j) - '0') * (*(q + i) - '0');
		}
	}
	for (int i = 1; i <= msz; i++) {
		if (temp[i] > 9) {
			temp[i + 1] += temp[i] / 10;
			temp[i] = temp[i] % 10;
		}
	}
	for (int i = 1; i <= msz; i++) {
		*(c + i) = temp[i] + '0';
	}
	if (*(p) != *(q)) {
		*(c) = '-';
	}
	if (*(p) == *(q)) {
		*(c) = '+';
	}
	//printf("[%s][%s][%s]\n", p, q, c);
	printans(c, msz);
}

void reset(char* a, char* b, char* c) {
	for (int i = 0; i < 2002; i ++ ) {
		*(a + i) = '0';
		*(b + i) = '0';
	}
	for (int i = 2002; i < 5100; i++) {		
		*(c + i) = '0';
	}
}


int main() {
	char a[2002] = { 0, }, b[2002] = { 0, }, c[5100];
	freopen("data.txt", "r", stdin);
	scanf("%s %s", A, B);
	strcopy(A, a); strcopy(B, b);
	fix(a); fix(b);
	arrage(a, b);
	fixp(a); fixp(b);
	add(a, b, c);

	reset(a, b, c);
	strcopy(A, a); strcopy(B, b);
	fix(a); fix(b);
	if (*(b) == '-') *(b) = '+';
	else  *(b) = '-';
	arrage(a, b);
	fixp(a); fixp(b);
	add(a, b, c);

	reset(a, b, c);
	strcopy(A, a); strcopy(B, b);
	fix(a); fix(b);
	arrage(a, b);
	fixp(a); fixp(b);
	mul(a, b, c);
	return 0;
}