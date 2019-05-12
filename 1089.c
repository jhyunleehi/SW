#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct heap *pheap;
typedef struct heap {
	int N[500001];
	int dir; //1: up, 2: down	
	int head;
	int tail;
};
void swap(int *A, int *B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

void addheap(struct heap *php, int n, int dir) {
	printf("addheap: %d\n", n);
	if (php->tail == 0) {
		php->tail = php->head = 1;;
		php->N[php->tail] = n;
	}
	else {
		php->tail++;
		php->N[php->tail] = n;
	}
	int down = php->tail;
	int up = (php->tail) / 2;
	while (down > 1) {
		if (dir == 1) {
			if (php->N[up] > php->N[down]) {
				swap(&php->N[up], &php->N[down]);
			}
		}
		if (dir == 2) {
			if (php->N[up] < php->N[down]) {
				swap(&php->N[up], &php->N[down]);
			}
		}
		down = up;
		up = up / 2;
	}
}

int getheap(struct heap *php,int dir) {
	int temp = php->N[1];
	if (php->tail <= 0) return -1;
	php->N[1] = php->N[php->tail];
	php->N[php->tail] = 0;
	php->tail--;
	int up = 1;
	int down = php->tail;
	while (up < down) {
		int key = -1;
		if (dir == 1) {
			for (int i = 0; i <= 1; i++) {
				if ((php->N[up] > php->N[up * 2 + i]) && (up * 2 + i < php->tail)) {
					swap(&php->N[up], &php->N[up * 2 + i]);					
					key = i;
				}
			}
		} else if (dir == 2) {
			for (int i = 0; i <= 1; i++) {
				if ((php->N[up] < php->N[up * 2 + i]) && (up * 2 + i < php->tail)) {
					swap(&php->N[up], &php->N[up * 2 + i]);									
					key = i;
				}
			}
		} 
		if (key == 0) up = up * 2;
		if (key == 1) up = up * 2+1;
		if (key == -1) break;
	}
	return temp;
}

int main() {
	freopen("data.txt", "r", stdin);
	struct heap *myheap = (struct heap*)(malloc(sizeof(struct heap)));	
	myheap->head = myheap->tail = 0;

	int N, dir;
	int in;
	scanf("%d %d", &N, &dir);
	for (int i = 0; i < N; i++) {
		scanf("%d", &in);
		addheap(myheap, in, dir);
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", getheap(myheap,dir));
	}
}
