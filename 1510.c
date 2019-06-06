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
void qsort(struct item *pi, int L, int R) {
	int p = L;
	int q = R;
	int v = (pi+((L + R) / 2))->a;
	int ta, tb;
	while (p <= q) {
		while ((pi + p)->a < v)p++;
		while ((pi + q)->a > v)q--;
		if (p <= q) {
			ta = (pi + p)->a; tb = (pi + p)->b;
			(pi + p)->a = (pi + q)->a;
			(pi + p)->b = (pi + q)->b;
			(pi + q)->a = ta; (pi + q)->b = tb;
			p++; q--;
		}
	}
	if (q > L)qsort(pi, L, q);
	if (p < R)qsort(pi, p, R);
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	struct item *pi = (struct item *)malloc(sizeof(struct item)*N);
	int a, b;
	int map[100][2] = { 0, };
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		(pi + i)->a = (a >= b) ? a : b;
		(pi + i)->b = (b > a) ? a : b;
	}
	qsort(pi, 0, N-1);
	for (int i = 0; i < N; i++)	printf("#%2d %3d %3d \n", i, (pi + i)->a, (pi + i)->b);

	for (int i = 1; i < N; i++) {
		for (int j = i; j >= 0; j--) {
			if ((pi + i)->b >= (pi + j)->b)
				map[i][0] ++;
		}
	}
	int cnt = 0;
	//map[0][0] = 1;	
	for (int i = 1; i < N; i++) {		
		for (int j = i; j >= 0; j--) {
			if ((pi + i)->b >= (pi + j)->b)
				if(map[i][1] <= map[j][1] + 1)
					map[i][1] = map[j][1] + 1;
			if (cnt < map[i][1]) cnt = map[i][1];
		}		
	}

	for (int i = 0; i < N; i++)	printf("#%2d [%3d] [%3d]\n", i, map[i][0], map[i][1]); 


	printf("%d\n", cnt+1);
}
