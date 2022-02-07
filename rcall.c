#include<stdio.h>
#include<malloc.h>
typedef struct node *pnode;
typedef struct node {
    int a,b;
    pnode next;
};
pnode head;
int step;
void rcall(int s){
    printf("call:[%d]\n", s);
    pnode node=(pnode)malloc(sizeof(struct node));
    node->a=step++;
    node->b=s;
    node->next=head;
    head=node;
    int local=s;
    if (s>0) rcall(s-1);
    return;
}

int main(){
    rcall(10);
}
