/**************************************************************
    Problem: 1102
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
typedef struct Link *link;
typedef struct Link {
    int   data;
    int   cnt;
    link  next;
};
 
int main() {
    int N;
    char *str = (char *)malloc(sizeof(char) * 10);
    link top = NULL;//(link) malloc(sizeof(link) + 1);
    link temp = NULL;
    //head->next = NULL;
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        switch (*(str)) {
        case 'o':
            if (top == NULL) {
                printf("empty\n");
            }
            else {
                link temp = top;
                printf("%d\n", temp->data);
                top = top->next;
                free(temp);
            }   
            break;
        case 'i':
            int i;
            scanf("%d",&i);
            temp = (link)malloc(sizeof(Link));
            temp->data = i;
            if (top != NULL)
                temp->cnt = top->cnt + 1;
            else
                temp->cnt = 1;
            temp->next = top;
            top = temp;
            break;
        case 'c':
            if (top != NULL)
                printf("%d\n", top->cnt);
            else
                printf("%d\n", 0);
            break;
        }
    }
 
    return 1;
}
