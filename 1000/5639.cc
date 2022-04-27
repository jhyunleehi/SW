#include <stdio.h>
#include <malloc.h>
typedef struct Node *pnode;
typedef struct Node
{
    int num;
    pnode llink;
    pnode rlink;
} node;

node head;
int N, count;
int no[10000], idx;

//전위입력
void buildt(node *node, int n)
{
    if (node->num == 0)
    {
        node->num = n;
        return;
    }

    if (node->num > n)
    {
        if (node->llink == NULL)
        {
            pnode newnode = (pnode)malloc(sizeof(struct Node));
            node->llink = newnode;
            buildt(node->llink, n);
        }
        else
        {
            buildt(node->llink, n);
        }
    }
    if (node->num < n)
    {
        if (node->rlink == NULL)
        {
            pnode newnode = (pnode)malloc(sizeof(struct Node));
            node->rlink = newnode;
            buildt(node->rlink, n);
        }
        else
        {
            buildt(node->rlink, n);
        }
    }
}

//중위탐색
void visit(node *node)
{
    if (node->llink != NULL)
        visit(node->llink);
    if (node->rlink != NULL)
        visit(node->rlink);
    printf("%d\n", node->num);
}
int main()
{
    freopen("data.txt", "r", stdin);
    int i = 0;
    for (i = 0; scanf("%d", &N) != EOF; i++)
    {
        no[i] = N;
    }
    count = i;
    for (int i = 0; i < count; i++)
    {
        buildt(&head, no[i]);
    }

    visit(&head);
}