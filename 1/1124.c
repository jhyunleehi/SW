#include<stdio.h>
#include<malloc.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void qsort(int *List, int left, int right) {
	if (left >= right) return;
	int pivot = List[(left+right)/2];
	int p = left, q = right;
	do {
		while (List[p] < pivot) p++;
		while (List[q] > pivot) q--;
		if (p <=q) {
			swap(&List[p], &List[q]);
			p++; q--;
		}
	} while (p <= q);
	if( left< q) qsort(List, left, q);
	if(right>p) qsort(List, p, right);
}

void dedup(int *List, int N, int *lx, int *cnt) {
	int temp = List[0];
	*cnt = 1;
	lx[0] = List[0];
	for (int i = 1; i <= N; i++) {
		if (temp != List[i]) {
			temp = List[i];
			lx[(*cnt)++] = List[i];			
		}
	}
	printf("%d \n", *cnt);
}

int main() {

	int Paper = 0;
	int paperx[101] = { 0, };
	int papery[101] = { 0, };
	int listx[200 + 1] = { 0, };
	int listy[200 + 1] = { 0, };
	int lx[200 + 1] = { 0, };
	int ly[200 + 1] = { 0, };
	int map[201][201] = { 0, };
	int result[201][201] = { 0, };
	
	freopen("data.txt", "r", stdin);
	scanf("%d", &Paper);
	for (int i = 0; i < Paper; i++) {
		scanf("%d %d", &paperx[i], &papery[i]);
		listx[i] = paperx[i];
		listy[i] = papery[i];
		listx[i + Paper] = listx[i] + 10;
		listy[i + Paper] = listy[i] + 10;
	}
	//for (int i = 0; i < Paper*2; i++)  printf("[%d] ", listx[i]); printf("\n");
	//for (int i = 0; i < Paper*2; i++)  printf("[%d] ", listy[i]); printf("\n");
	
	qsort(listx, 0, Paper * 2 - 1);
	qsort(listy, 0, Paper * 2 - 1);
	//for (int i = 0; i < Paper * 2; i++)  printf("[%d] ", listx[i]); printf("\n");
	//for (int i = 0; i < Paper * 2; i++)  printf("[%d] ", listy[i]); printf("\n");
	
	int cntx = 0;
	int cnty = 0;
	dedup(listx, Paper * 2 - 1, lx, &cntx);
	dedup(listy, Paper * 2 - 1, ly, &cnty);
	//for (int i = 0; i < cntx; i++)  printf("[%d] ", lx[i]); printf("\n");
	//for (int i = 0; i < cnty; i++)  printf("[%d] ", ly[i]); printf("\n");
	//cntx, xnty is number of line
	
	int boxx = cntx - 1;
	int boxy = cnty - 1;
	for (int y = 0; y < boxy; y++) {
		for (int x = 0; x < boxx; x++) {
			//printf("%d %d\n", x, y);
			map[y][x] = 0;
			for (int k = 0; k < Paper; k++) {
				if ((paperx[k] <= lx[x]) && (papery[k] <= ly[y]) &&
					(paperx[k] + 10 >= lx[x + 1]) && (papery[k] + 10 >= ly[y + 1])) {
					map[y][x] = (lx[x + 1] - lx[x])*(ly[y + 1] - ly[y]);
					//map[y][x] = 1;
					break;
				}
			}
		}
	}
	for (int y = boxy - 1; y >= 0; y--) {
		for (int x = 0; x < boxx; x++)
			printf("[%d]", map[y][x]);
		printf("\n");
	}	
	printf("\n");
	for (int y = 0; y < boxy; y++) {
		for (int x = 0; x < boxx; x++) {
			bool good = true;
			int sum = 0;
			for (int i = y; i < boxy; i++) {
				for (int j = x; j < boxx; j++)
					if (map[i][j] == 0) {
						good = false;
						break;
					}
					else {
						sum += map[i][j];
						if ((good) && (result[i][j] < sum)) result[i][j] = sum;
					}
					
			}
		}
	}

	for (int y = boxy - 1; y >= 0; y--) {
		for (int x = 0; x < boxx; x++)
			printf("[%d]", result[y][x]);
		printf("\n");
	}

	/*
	for (int y = 0; y < boxy; y++) {
		for (int x = 0; x < boxx; x++) {			
			bool pinx = true;
			bool piny = true;
			int boundx = x;
			int boundy = y;
			while (pinx || piny) {
				if (piny) {
					for (int i = x; i <= boundx; i++) {
						if (map[boundy][x] == 0) { piny = false; break; }
					}
					if(piny) boundy++;
				}
				if (pinx) {
					for (int i = y; i <= boundy; i++) {
						if (map[i][boundx] == 0) { pinx = false; break; }
					}
					if(pinx) boundx++;
				}
				printf("y[%d] x[%d] boundy[%d] boundx[%d] \n", y, x, boundy, boundx);
			}
		}
	}
	*/

					
	return 1;
}
