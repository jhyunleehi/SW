#include<stdio.h>
#include<malloc.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void qsort(int *List, int left, int right) {
	if (left >= right) return;
	int pivot = List[(left + right) / 2];
	int p = left;
	int q = right;
	do{
		while (List[p] < pivot) p++;
		while (List[q] > pivot)q--;
		if (p <= q) {
			swap(&List[p], &List[q]);
			p++; q--;
		}
	} while (p < q);
	if (left < q) qsort(List, left, q);
	if (right > p)qsort(List, p, right);
}

void dedup(int *List, int cnt, int* nList, int *ncnt) {
	int temp= List[0];
	int count = 1;
	nList[0] = List[0];
	//printf("\n"); for (int i = 0; i < cnt; i++) printf("[%d]", List[i]);
	for (int i = 1; i < cnt; i++) {
		if (List[i] != temp) {
			nList[count++] = List[i];
			temp= List[i];
		}
	}
	*ncnt = count;
	printf("\n"); for (int i = 0; i < count; i++) printf("[%d]", nList[i]);
}

int main() {
	int P = 0;
	int pxlist[101];
	int pylist[101];
	int xlist[201];
	int ylist[201];
	int lx[201];
	int ly[201];
	int xcnt, ycnt;
	int map[201][201];
	freopen("data.txt", "r", stdin);
	scanf("%d", &P);
	for (int i = 0; i < P; i++) {
		scanf("%d %d", &pxlist[i], &pylist[i]);
		xlist[i] = pxlist[i];
		ylist[i] = pylist[i];
		xlist[i + P] = pxlist[i] + 10;
		ylist[i + P] = pylist[i] + 10;
	}
	qsort(xlist, 0, P * 2 - 1);
	qsort(ylist, 0, P * 2 - 1);
	dedup(xlist, P * 2, lx, &xcnt);
	dedup(ylist, P * 2, ly, &ycnt);

	for (int y = 0; y < ycnt-1; y++) {
		for (int x = 0; x < xcnt-1; x++) {
			map[y][x] = 0;			
			for (int p = 0; p < P; p++) {
				//printf("%d %d %d \n", y, x, p);				
				if ((pxlist[p] <= lx[x]) && (pylist[p] <= ly[y])
					&& (pxlist[p] + 10 >= lx[x + 1]) && (pylist[p] + 10 >= ly[y + 1])) {
					if(map[y][x]==0) map[y][x] = p+1;
					else map[y][x] = -1;//overlay
				}				
			}
		}
	}

	printf("\n[%d][%d]\n",ycnt, xcnt);
	for (int y = ycnt - 2; y >= 0; y--) {
		for (int x = 0; x < xcnt - 1; x++) {
			printf("%2d", map[y][x]);
		}
		printf("\n");
	}

	int sum = 0;
	int cnt = 0;
	for (int y = 0; y < ycnt - 1; y++) {
		for (int x = 0; x < xcnt - 1; x++) {
			//sum = 0;
			if ((map[y][x] != -1) && (map[y][x] != 0)) {
				int s = map[y][x]-1;
				//왼쪽
				cnt = 0;
				for (int p = 0; p < P; p++) {
					if ((lx[x] == pxlist[p] + 10) &&
						(ly[y] >= pylist[p]) && (ly[y + 1] <= pylist[p] + 10)) cnt++;
				}
				if ((cnt==0)&&(lx[x] == pxlist[s]))
					sum += ly[y + 1] - ly[y];
				//오른쪽
				cnt = 0;
				for (int p = 0; p < P; p++) {
					if ((lx[x + 1] == pxlist[p]) &&
						(ly[y] >= pylist[p]) && (ly[y + 1] <= pylist[p] + 10)) cnt++;
				}
				if((cnt==0)&&(lx[x + 1] == pxlist[s] + 10))
					sum += ly[y + 1] - ly[y];
				//아래
				cnt = 0;
				for (int p = 0; p < P; p++) {
					if ((ly[y] == pylist[p] + 10) &&
						(lx[x] >= pxlist[p]) && (lx[x + 1] <= pxlist[p] + 10)) cnt++;
				}
				if((cnt==0)&&(ly[y] == pylist[s]))
					sum += lx[x + 1] - lx[x];
				//위
				cnt = 0;
				for (int p = 0; p < P; p++) {
					if ((ly[y + 1] == pylist[p]) &&
						(lx[x] >= pxlist[p]) && (lx[x + 1] <= pxlist[p] + 10)) cnt++;
				}
				if((cnt==0)&&(ly[y + 1] == pylist[s] + 10))
					sum += lx[x + 1] - lx[x];
			}
			printf("%d %d %d\n", y, x, sum);
		}
	}
	printf("%d\n", sum);

	return 1;
}
