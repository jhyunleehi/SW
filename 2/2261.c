/*
1. 각각의 코드간에 해밍거리가 되는지 여부를 매번 판단하는 것은 비용이 발생
2. 따라서 각각의 코드간에 미리 해밍거리가 되는지 여부를 그래프 형태로 재구성
3. 생성된 그래프를 이용하여 최소 도달 경로를 역추적하여 제공
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Node *pNode;
typedef struct Node {
	int N;
	pNode next;
};

int N, M;
int *List;
int **Map;
int *visit;

pNode *pList;


bool chkhaming(int a, int b) {
	int k = a ^ b;
	return !(k&(k - 1));
}

void pList_add(int x, int y) {
	printf("pList_add %d %d\n", x, y);
	pNode newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->N = y;
	newNode->next = NULL;
	pNode temp= *(pList + x);
	if (temp == NULL) {
		*(pList + x) = newNode;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void pList_print(int x) {
	printf("pList_print: %d\n", x);
	pNode temp = *(pList + x);
	if (temp == NULL) {
		printf("NULL\n");
		return;
	}
	while (temp->next != NULL) {
		printf("[%d]->", temp->N);
		temp = temp->next;
	}
	printf("[%d]\n", temp->N);
}

int enqueue(pNode *head, pNode *rear, int N) {
	printf("enqueue %d\n", N);
	pNode newNode = (pNode)malloc(sizeof(struct Node));
	newNode->N = N;
	newNode->next = NULL;
	if (*head == NULL && *rear == NULL) {
		*head = *rear = newNode;
		return -1;
	}
	(*rear)->next = newNode;
	*rear = newNode;
	return 0;
}
int dequeue(pNode *head, pNode *rear) {
	printf("dequeue\n");
	pNode temp = *head;
	if (*head == NULL) return -1;
	if (*head == *rear) {
		*head = *rear = NULL;
		return 0;
	}
	free(temp);
	return 0;
}
int gethead(pNode *head) {
	if (head == NULL) return NULL;
	return (*head)->N;
}

int main() {
	int S, E;
	char str[32];
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	List = (int*)malloc(sizeof(int)*N + 1);
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		//printf("%s \n", str);
		int num = 0;
		for (int j = 0; j < M; j++) {
			if (str[j] == '1')
				num += 1 << ((M - j) - 1);
		}
		*(List + i) = num;
		printf("%d %d \n", i, *(List + i));
	}
	scanf("%d %d", &S, &E);
	S--;
	E--;

	pList = (pNode*) malloc(sizeof(pNode)*N + 1);
	for (int i = 0; i < N; i++) *(pList + i) = NULL;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (chkhaming(*(List + i), *(List + j))) {
					pList_add(i, j);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) pList_print(i);			
	visit = (int*)malloc(sizeof(int*)*N + 1);
	for (int i = 0; i < N; i++) *(visit+i) = 0;
	pNode head = NULL;
	pNode rear = NULL;
	int next;
	int cnt = 1;
	enqueue(&head, &rear, S);
	while (head != NULL) {
		next = gethead(&head);
		dequeue(&head, &rear);
		*(visit + next) = cnt++;
		if (next == E) break;
		pNode temp = *(pList + next);
		while (temp->next !=NULL) {
			if (*(visit + (temp->N)) == 0) {
				enqueue(&head, &rear, temp->N);
			}
			temp = temp->next;
		}
		enqueue(&head, &rear, temp->N);
	}
	for (int i = cnt-1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (*(visit + j) == i)
				printf("%d", j);
		}
	}
}
