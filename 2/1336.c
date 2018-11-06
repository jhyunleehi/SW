/*
1. 소수와 함께하는 여행
2. 소수 목록을 추출
3. 소수 목록간 그래프 구성
4. BFS 탐색을 통해서 최소 경로 탐색
5. 소수구하기 https://twpower.github.io/79-usage-of-memset-function
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct node *pnode;
typedef struct node{
	int n;
	int cnt;
	pnode next;
};

void add_map_list(pnode *map_list, int s, int e);
void print_map_list(pnode *map_list, int s);

int main() {
	
	int S, E;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &S, &E);
	int prime[9999 + 1]; //0000 ~ 9999 
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= 9999; i++) {
		if (prime[i] == 0) {
			for (int j = i * 2; j <= 9999; j += i) {
				prime[j] = 1;
			}
		}
	}
	int cnt = 0;	
	for (int i = 1000; i <= 9999; i++) {
		if (prime[i] == 0) {
			cnt++;
		}
	}
	int **Map = (int**)malloc(sizeof(int*)*(cnt + 1));
	for (int i = 0; i < cnt; i++) {
		*(Map + i) = (int*)malloc(sizeof(int)*(cnt + 1));
		memset(*(Map + i), 0, sizeof(*(Map + i))*cnt);
	}
	int t;
	for (int i = 1000; i <= 9999; i++) {
		for (int j = 1000; j <=9999 ; j++) {
			if (!(i == j) &&(prime[i] == 0)&&(prime[j] == 0)) {
				t = i - j;
				t = (t >= 0) ? t : -1 * t;
				if ((t < 10) || (t % 10 == 0)) {
					*(*(Map + i) + j) = 1;				
				}
			}
		}
	}

	pnode *map_list;
	map_list = (pnode*)(malloc(sizeof(struct node)*10000));
	for (int i = 1000; i <=9999; i++) 	*(map_list + i) = NULL;

	for (int i = 1000; i <=9999; i++) {
		for (int j = 1000; j <=9999; j++) {
			if (*(*(Map + i) + j) == 1)
				add_map_list(map_list,i, j);			
		}
	}
	for (int i = 1000; i <=9999; i++) {
		print_map_list(map_list, i);
	}

}

void add_map_list(pnode *map_list, int s, int e) {
	pnode new_node = (pnode)malloc(sizeof(struct node));
	new_node->cnt = 0;
	new_node->n = e;
	new_node->next = NULL;
	if (*(map_list + s) == NULL) {
		*(map_list + s) = new_node;
	}
	else {
		pnode next_node = *(map_list + s);
		while (next_node->next != NULL) {
			next_node = next_node->next;
		}
		next_node->next = new_node;
	}
}

void print_map_list(pnode *map_list, int s) {
	pnode temp = *(map_list + s);
	if (temp == NULL) return;
	while (temp->next != NULL) {
		printf("[%d]->", temp->n);
		temp = temp->next;
	}
	printf("[%d]\n", temp->n);
}
