#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct node *pnode;
typedef struct node {
	int num;
	pnode next;
};
typedef struct list *plink;
typedef struct list {
	int cnt;
	pnode head;
};

bool list_search(struct list *mylist, int no) {
	struct node *temp = mylist->head;
	while (temp != NULL) {
		if (temp->num == no) return true;
		temp = temp->next;
	}
	return false;
}

void list_add(struct list *mylist, int no) {	
	struct node *nnode = (struct node*) malloc(sizeof(struct node));
	nnode->num = no;
	nnode->next = NULL;	
	if (mylist->head == NULL) {
		mylist->head = nnode;
		mylist->cnt++;
	}
	
	if (list_search(mylist, no)) return;;

	if (mylist->head->num < no) {
		nnode->next = mylist->head;
		mylist->head = nnode;
		mylist->cnt++;
	} else{
		struct node *temp = mylist->head;		
		while (temp->next != NULL) {
			if (temp->num > no) {
				nnode->next = temp->next;
				temp->next = nnode;
				mylist->cnt++;
				break;
			}
			temp = temp->next;
		}
	}
}

void tsort(char *t1, char *t2, char *t3) {
	char temp;
	if (*t1 < *t2) {
		temp = *t2;
		*t2 = *t1;
		*t1 = temp;
	}
	if (*t1 < *t3) {
		temp = *t3;
		*t3 = *t1;
		*t1 = temp;
	}
	if (*t2 < *t3) {
		temp = *t3;
		*t3 = *t2;
		*t2 = temp;
	}
}
bool find(char mylist[][3], int s, int e, int t1) {
	if (s > e) return false;
	int mid = (s+e) / 2;
	if (mylist[mid][0] == t1) return true;
	if (mylist[mid][0] < t1)
		return find(mylist, s, mid-1, t1);
	else
		return find(mylist, mid+1,e, t1);
}


int main() {
	freopen("data.txt", "r", stdin);
	int N;
	int cnt = 0;
	scanf("%d", &N);
	//struct list *mylist = (plink)(malloc(sizeof(struct list)));
	//mylist->cnt = 0;
	//mylist->head = NULL;
	char mylist[50000+1][3] = { 0, };
	char t1, t2, t3;
	for (int a = 1; a < N; a++) {
		for (int b = 1; b < N - a; b++) {
			int c = (N - (a + b));
			if((a>= b+c) || (b>=a+c)||(c>=a+b)) continue;
			t1 = a; t2 = b; t3 = c;
			tsort(&t1, &t2, &t3);

			int i = 0;
			while (mylist[i][0] != 0) {
				if ((mylist[i][0] == t1) && (mylist[i][1] == t2) && (mylist[i][2] == t3))
					break;
				i++;
			}
			if (mylist[i][0] == 0) {
				mylist[i][0] = t1;
				mylist[i][1] = t2;
				mylist[i][2] = t3;
				cnt++;
				printf("%d %d %d\n", t1, t2, t3);
			}

			/*
			if (!find(mylist, 0, cnt, t1)) {
				mylist[cnt][0] = t1;
				mylist[cnt][1] = t2;
				mylist[cnt][2] = t3;
				cnt++;
				printf("%d %d %d\n", t1, t2, t3);
			}
			*/
		}
	}
	printf("%d\n", cnt);
}
