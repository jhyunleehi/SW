#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	char str[10];
	int  M[10] = { 1, };
	int i = 0;
	int idx = 0;
	int cnt = 0;
	while (i < 3) {
		i++;
		scanf("%s", str);
		idx = 0;
		int temp = *(str+idx) - '0';
		idx++;
		cnt = 1;
		while (*(str + idx) != NULL) {
			if (temp == (*(str + idx) - '0') ) {
				cnt++;
				if (M[temp] < cnt) M[temp] = cnt;
			}else{
				cnt=1;
				temp = (*(str + idx) - '0');
			}
			idx++;
		}
		int maxCnt = 0x7fffffff + 1;
		for (int k = 0; k <= 9; k++) {
			if (M[k] > maxCnt) maxCnt = M[k];
			M[k] = 1;
		}
		printf("%d\n", maxCnt);
	}
}
