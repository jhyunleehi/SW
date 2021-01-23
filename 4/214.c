#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char M[10][100 + 1];
char chk_ch;
int cnt;
int chk;
void swap(char *A, char *B) {
	char temp[101];	
	int i = 0;
	while (*(A + i) != '\0') temp[i] = *(A + i++);
	temp[i] = '\0';
	i = 0;
	while (*(B + i) != '\0') *(A + i) = *(B + i++);
	*(A+i) = '\0';
	i = 0;
	while (temp[i] != '\0') *(B + i) = temp[i++];
	*(B + i) = '\0';
}


int main() {
	freopen("data.txt", "r", stdin);
	for (int i = 0; i < 10; i++) {
		scanf("%s", M[i]);
	}
	scanf("%s", &chk_ch);
	for (int i = 0; i < 10; i++) {
		chk = 0;
		for (int j = 0; j < 100; j++) {
			if (M[i][j] == chk_ch) {
				chk = 1;
				break;
			}
			if (M[i][j] == '\0') break;
		}
		if (chk == 0) M[i][0] = '\0';
	}
	for(int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			int k = 0;
			if (M[i][k] == '\0') break;
			if (M[j][k] == '\0') continue;
			while (M[i][k] != '\0') {
				if (M[i][k] > M[j][k]) {
					swap(M[i], M[j]);
					break;
				}
				else if (M[i][k] < M[j][k]){
					break;
				}
				k++;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (M[i][0] != '\0')printf("%s\n", M[i]);
	}
}
