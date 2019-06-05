#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct item *pitem;
typedef struct item {
	int a;
	int b;
};

int N;
int map[101][101];
int count = 0;
void rcall(int row, int depth) {
	//printf("st:%d   depth:%d\n", row, depth);
	int cnt = 0;
	depth++;
	if (depth > count) {
		count = depth;		
	}
	for (int j = 0; j < N; j++)
		if (map[row][j] != 0) cnt++;
	if (cnt == 0) return;
	for (int j = 0; j < N; j++) {
		if (map[row][j] != 0) {
			rcall(j, depth);
			map[row][j] = count;
		}
	}
}
int main() {
	freopen("data.txt", "r", stdin);	
	scanf("%d", &N);
	struct item *pi = (struct item *)malloc(sizeof(struct item)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &(pi+i)->a, &(pi+i)->b);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) { map[i][j] = 0; continue; }
			if ((((pi + i)->a >= (pi + j)->a) && ((pi + i)->b >= (pi + j)->b)) ||
				(((pi + i)->a >= (pi + j)->b) && ((pi + i)->b >= (pi + j)->a)) )				
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
	int cnt;
	int max = 0x7fffffff + 1;
	int st;
	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			//printf("[%d] ", map[i][j]);
			if (map[i][j] == 1) cnt++;
			if (cnt > max) { max=cnt; st = i; }
		}
		//printf("\n");
	}
	cnt = 0;
	rcall(st, 0);

	for (int i = 0; i < N; i++) {	
		for (int j = 0; j < N; j++) {
			printf("[%d] ", map[i][j]);	
		}
		printf("\n");
	}

	printf("%d\n", count);
}
