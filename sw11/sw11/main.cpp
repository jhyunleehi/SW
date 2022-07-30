#include <stdio.h>
#include<malloc.h>
typedef struct node* pnode;
typedef struct node {
	char C;
	pnode  L;
	pnode R;
};
pnode createNode(char c, pnode left, pnode right ) {
	pnode p = (pnode)malloc(sizeof(node));
	p->C = c;
	p->L = left;
	p->R = right;
	return p;
}

void buildTree(pnode h, char c, char * bin){


int N;
pnode htree;
int main() {
	char C;
	char bin[20];
	htree = (pnode)malloc(sizeof(node));
	htree->C = '\0'; htree->L = NULL; htree->R = NULL;;
	freopen("data.txt", "r", stdin);
	scanf("%d", &N); {
		for (int i = 0; i < N; i++) {
			scanf("%c %s", &C, &bin);
			int j = 0;
			while (buffer[j] != '\0') {
				buildTree(htree, C, bin);
			}
		}
	}
}