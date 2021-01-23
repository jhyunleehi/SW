#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct node *pnode;
typedef struct node {
    int num;
    pnode L;
    pnode R;
};
 
typedef struct heap *ph;
typedef struct heap {
    int M[500000 + 1];
    int root;
    int tail;
};
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}
 
void printheap(struct heap *ph) {
    for (int i = 1; i <= ph->tail; i++) {
        printf("[%d]", ph->M[i]);
    }
    printf("\n");
}
 
void addheap(struct heap *ph, int in, int dir) {
    if (ph->tail == 0) {
        ph->root = ph->tail = 1;
        ph->M[ph->tail] = in;
    }
    else {
        ph->tail++;
        ph->M[ph->tail] = in;
    }
    int pnode = ph->tail / 2;
    int cnode = ph->tail;
    while (pnode >= 1) {
        if (dir == 1) {
            if (ph->M[pnode] > ph->M[cnode]) {
                swap(&ph->M[pnode], &ph->M[cnode]);
                cnode = pnode;
                pnode = pnode / 2;
            }
            else {
                break;
            }
        }
        if (dir == 2) {
            if (ph->M[pnode] < ph->M[cnode]) {
                swap(&ph->M[pnode], &ph->M[cnode]);
                cnode = pnode;
                pnode = pnode / 2;
            }
            else {
                break;
            }
        }
 
    }
}
void getheap(struct heap *ph, int dir) {
    if (ph->root > ph->tail) return;
    printf("%d\n", ph->M[ph->root]);
    ph->M[ph->root] = ph->M[ph->tail];
    ph->M[ph->tail] = 0;
    ph->tail--;
    int pnode = ph->root;
    int Lnode = pnode * 2;
    int Rnode = pnode * 2 + 1;
    int pri;
    while ((pnode * 2) <= ph->tail) {
        if (Rnode <= ph->tail) {
            if (dir == 1)   pri = (ph->M[Lnode] <= ph->M[Rnode]) ? Lnode : Rnode;
            if (dir == 2)   pri = (ph->M[Lnode] >= ph->M[Rnode]) ? Lnode : Rnode;
        }
        else if ((Rnode > ph->tail) && (Lnode <= ph->tail)) {
            pri = Lnode;
        }
        if (dir == 1) {
            if (ph->M[pnode] > ph->M[pri]) {
                swap(&ph->M[pnode], &ph->M[pri]);
                pnode = pri;
                Lnode = pnode * 2;
                Rnode = pnode * 2 + 1;
            }
            else {
                break;
            }
        }
        if (dir == 2) {
            if (ph->M[pnode] < ph->M[pri]) {
                swap(&ph->M[pnode], &ph->M[pri]);
                pnode = pri;
                Lnode = pnode * 2;
                Rnode = pnode * 2 + 1;
            }
            else {
                break;
            }
        }
 
 
    }
}
 
int main() {
    //freopen("data.txt", "r", stdin);
    int N, dir;
    int in;
    scanf("%d %d", &N, &dir);
    struct heap *ph = (struct heap *)(malloc(sizeof(struct heap)));
    ph->root = 0;
    ph->tail = 0;
    ph->M[0] = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &in);
        addheap(ph, in, dir);
        //printheap(ph);
    }
    for (int i = 0; i < N; i++) {
        getheap(ph,dir);
        //printheap(ph);
    }
 
}
