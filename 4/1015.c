#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

char ignored_mgs[] = "Ignored";
bool strcmp(char *src, char *dest);
bool strcpy(char *src, char *dest);

typedef struct node *pNode;
typedef struct node{
	char *url;
	pNode next;
	pNode prev;
};

typedef struct stack *pStack;
typedef struct stack {
	pNode head;	
	pNode tail;
	pNode top;	
	int count;
};

void push(struct stack *pS, char *new_url) {
	//printf("[push]: %s \n", new_url);
	pNode temp = (pNode)malloc(sizeof(struct node));
	int len = 0;
	while (*(new_url + len) != '\0') ++len;
	char *str = (char*)malloc(sizeof(char)*(len + 1));
	strcpy(new_url, str);
	temp->url = str;
	temp->prev = pS->top;
	temp->next = NULL;
	if (pS->count <= 0) {
		temp->prev = NULL;;
		pS->head = pS->tail= pS->top = temp;
	}else {		
		pS->top->next = temp;
		pS->tail->next = temp;
		pS->top = temp;
		pS->tail = temp;
	}
	pS->count++;
}

void pop(struct stack *pS, char *get_url) {
	//printf("[pop]: %s\n");
	if (pS->count <= 0) {		
		strcpy(ignored_mgs, get_url);
		return;
	}
	pNode temp = pS->tail;
	if (pS->head == pS->tail) {
		pS->head = pS->tail = NULL;
	} else {
		strcpy(pS->tail->url, get_url);
		pS->tail = pS->tail->next;
	}
	free(temp);
	pS->count--;
}

void back(struct stack *pS, char *get_url) {
	//printf("[back]: \n");
	if (pS->top->prev != NULL) {
		pS->top = pS->top->prev;
		strcpy(pS->top->url, get_url);
	}
	else {
		strcpy(ignored_mgs, get_url);
	}
}

void forward(struct stack *pS, char *get_url) {
	//printf("[forward]: \n");
	if (pS->top->next != NULL) {
		pS->top = pS->top->next;
		strcpy(pS->top->url, get_url);
	}
	else {
		strcpy(ignored_mgs, get_url);
	}
}



bool strcpy(char *src, char *dest) {
	int i = 0;
	while (*(src + i) != '\0') {
		*(dest + i) = *(src + i);
		i++;		
	}
	*(dest + i) = '\0';
	return true;
}


bool strcmp(char *src, char *dest) {
	int len_s = 0;
	int len_t = 0;
	while( *(src+len_s) != '\0')
		++len_s;
	while (*(dest+len_t) != '\0')
		++len_t;
	int len = (len_s >= len_t) ? len_s : len_t;
	int i = 0;
	while (*(src+i) == *(dest+i)) {
		i++;
		if (i == len) return true;
	}
	return false;
}


int main() {
	char cmd[100];
	char url[100];
	char home[] = "http://www.acm.org/";
	char get_url[100];
	freopen("Text.txt", "r", stdin);
	pStack pS = (pStack)malloc(sizeof(struct stack));
	pS->count = 0;
	push(pS, home);
	while (true) {
		scanf("%s ", cmd);
		char CMD = *cmd;
		switch (CMD) {
		case 'V':
			scanf("%s ", url);
			printf("%s\n", url);
			push(pS, url);
			break;
		case 'B':
			back(pS, url);
			printf("%s\n", url);
			break;
		case 'F':
			forward(pS, url);
			printf("%s\n", url);
			break;
		case 'Q':
			return 0;
			break;
		}
	}
	return 0;
}
