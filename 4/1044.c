#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Node *pNode;
typedef struct Node {
	int val;
	pNode L;
	pNode R;
};

void call(struct Node *pNode, int in) {
	//printf("[%d] %d\n", pNode->val, in);
	struct Node *temp;
	if (pNode->val == in) return;
	else if (pNode->val > in) {
		if (pNode->L == NULL) {
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->val = in;
			temp->L = NULL;
			temp->R = NULL;
			pNode->L = temp;
		}
		call(pNode->L, in);
	}
	else if (pNode->val < in) {
		if (pNode->R == NULL) {
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->val = in;
			temp->L = NULL;
			temp->R = NULL;
			pNode->R = temp;
		}
		call(pNode->R, in);
	}
}

int getmax(pNode root) {
	if (root->R == NULL)
		return root->val;
	else
		getmax(root->R);
}

int getmin(pNode root) {
	if (root->L == NULL)
		return root->val;
	else
		getmin(root->L);
}

int main() {
	freopen("data.txt", "r", stdin);
	int N = 10;
	int min, max;
	pNode root = (struct Node*)malloc(sizeof(struct Node));
	int i = 1;
	int in;	
	scanf("%d", &in);
	root->val = in;
	root->L = NULL;
	root->R = NULL;	
	while (i < N) {
		i++;
		scanf("%d", &in);
		call(root, in);
	}	
	printf("%d\n", getmax(root) - getmin(root));
}
