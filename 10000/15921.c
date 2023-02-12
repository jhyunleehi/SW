#include <stdio.h>
#include<malloc.h>
#define MAX_TABLE 789123

char str[1001];
char dst[1001];

typedef struct node *pnode;
typedef struct node {
	char str[1001];
	pnode next;
};

pnode head[MAX_TABLE];
int result;
int node_cnt;


void nstrcpy (char *s, char *t, int offset){
	int i = 0;
	for (i = 0; i < offset; i++) {
		*(t + i) = *(s + i);
	}	
	*(t + i) = '\0';
	return;
}

int hashing(char * s) {
	unsigned int h =1;	
	int k = 0;

	while (*s) {	
		h = ((h << 5) + *s);//% MAX_TABLE;;
		s++;
		if (h> MAX_TABLE) h=  h % MAX_TABLE;
	}
	return h % MAX_TABLE;
}

void strcpy(char* s, char* t) {	
	while ((*t = *s) != NULL) {		
		t++; s++;
	}
}

int strcmp(char* p, char* q) {
	while (*p && *p == *q) { p++; q++; }
	return *p - *q;
}

void insert_list(char *s) {
	int key = hashing(s);
	pnode h = head[key];
	pnode temp = (pnode)malloc(sizeof(struct node));	
	strcpy(s, temp->str);
	temp->next = NULL;	

	int cnt = 0;
	if (h==NULL) {
		head[key] = temp;
		result++;
		//printf("[%s][%s]\n", s, temp->str);
	}
	else {	
		//printf("[%d][%s]\n", key,s);
		while (h != NULL) {
			cnt++;
			if (0 == strcmp(h->str, s)) {
				return;
			}
			if (h->next == NULL) {
				h->next = temp;
				result++;
				//printf("[%d]\n", cnt);
			}
			else {
				h = h->next;
			}
		}
		
	}
	return;
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%s", str);
	int len = 0;
	while (str[len])len++;
	for (int idx = 1; idx<=len; idx++) {
		for (int i = 0; i <= len - idx; i++) {
			nstrcpy(&str[i], dst, idx );
			printf("%s\n", dst);
			insert_list(dst);
		}
	}
	printf("%d\n", result);
}