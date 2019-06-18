#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int main() {
	freopen("data.txt", "r", stdin);
	int mapCnt;
	int chkCnt;
	int cnt = 0;
	int sum = 0;
	int srcMap[50 + 1];
	int srcMapR[50 + 1];
	int tgtMap[100][50 + 1];
	int resultList[100] = { 0, };
	scanf("%d", &mapCnt);
	for (int i = 0; i < mapCnt; i++) {
		scanf("%d", &srcMap[i]);
		switch (srcMap[i]) {
		case 1:
			srcMapR[(mapCnt - 1) - i] = 3;
			break;
		case 2:
			srcMapR[(mapCnt - 1) - i] = 4;
			break;
		case 3:
			srcMapR[(mapCnt - 1) - i] = 1;
			break;
		case 4:
			srcMapR[(mapCnt - 1) - i] = 2;
			break;
		}
	}
	scanf("%d", &chkCnt);
	sum = 0;
	for (int i = 0; i < chkCnt; i++) {
		for (int j = 0; j < mapCnt; j++) {
			scanf("%d", &tgtMap[i][j]);
		}		
		for (int n = 0; n < mapCnt; n++) {
			cnt = 0;			
			for (int k = 0; k < mapCnt; k++) {
				if (srcMap[k] != tgtMap[i][(k + n) % mapCnt])
					break;
				else
					cnt++;
			}
			if (cnt == mapCnt) {
				resultList[i] = 1;
				sum++;
				break;
			}
			cnt = 0;
			for (int k = 0; k < mapCnt; k++) {
				if (srcMapR[k] != tgtMap[i][(k + n) % mapCnt])
					break;
				else
					cnt++;
			}
			if (cnt == mapCnt) {
				resultList[i] = 1;
				sum++;
			}
		}
	}
	printf("%d\n", sum);
	for (int i = 0; i < chkCnt ; i++) {
		if (resultList[i] == 1) {
			for (int j = 0; j < mapCnt; j++) {
				printf("%d ", tgtMap[i][j]);
			}
			printf("\n");
		}
		
	}
}
