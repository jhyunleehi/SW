#include<stdio.h>
#include<malloc.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *N, int Left, int Right) {
	if (Left>= Right) return;	
	int pivot = *(N + (Left+Right)/2);
	int p = Left, q = Right ;
	do{
		while ( (pivot > *(N + p))) p++;
		while ( (pivot < *(N + q))) q--;
		if (p<=q) {
			if(*(N+p) !=*(N+q))	
				swap(N+p, N+q);
			p++; q--;
		}		
	} while (p <= q);	
	sort(N, Left, q);
	sort(N, p, Right);
}

void inbox(int x1, int y1, int x2, int y2, int ** box, int N, int** Map) {
	int X,Y;
	for (int i = 0; i < N; i++) {
		X = *(*(box + i) + 0);
		Y = *(*(box + i) + 1);
	}
}

int main() {
	int N;
	int *IX, *IY;
	int cntX, cntY;
	int NX[101], NY[101];
	int box[101][2];
	int Map[201][201] = { 0, };
	int MapS[201][201] = { 0, };
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	IX = (int*)malloc(sizeof(int)*2*(N + 1));
	IY = (int*)malloc(sizeof(int)*2*(N + 1));
	for (int i = 0; i < N; i++) {
		scanf("%d %d", IX + i, IY + i);
		*(IX + N + i) = *(IX + i)+10;
		*(IY + N + i) = *(IY + i)+10;
		box[i][0] = *(IX + i);
		box[i][1] = *(IY + i);
	}
	for (int i = 0; i < 2 * N; i++)
		printf("%d ", *(IX + i));
	printf("\n");
	for (int i = 0; i < 2 * N; i++)
		printf("%d ", *(IY + i));
	printf("\n");

	sort(IX, 0, 2*N-1);
	sort(IY, 0, 2*N-1);
	
	for (int i = 0; i < 2 * N; i++)
		printf("%d ", *(IX + i));
	printf("\n");
	for (int i = 0; i < 2 * N; i++)
		printf("%d ", *(IY + i));
	printf("\n");

	cntX = 0;
	cntY = 0;
	NX[cntX] = *(IX);
	NY[cntY] = *(IY);
	for (int i = 0; i < 2 * N; i++) {
		if(NX[cntX] != *(IX + i))	NX[++cntX] = *(IX + i);
		if (NY[cntY] != *(IY + i))	NY[++cntY] = *(IY + i);
	}
	printf("%d %d \n", cntX, cntY);

	for (int i = 0; i < cntX; i++) //X
		for (int j = 0; j < cntY; j++) { //Y
			for (int k = 0; k < N; k++) { //box
				if ((*(IX + i) >= box[k][0]) && (*(IY + j) >= box[k][1]) &&
					(*(IX + i + 1) <= box[k][0] + 10) && (*(IY + j + 1) <= box[k][1] + 10)) {
					Map[i][j] = 1;
					break;
				}								
			}

		}
	

	for (int i = cntY; i >=0 ; i--) {
		for (int j = 0; j <cntX; j++) 
			printf("[%d]", Map[j][i]);
		printf("\n");
	}	

	return 1;
}
