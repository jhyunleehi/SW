/**************************************************************
    Problem: 1336
    User: jhyunlee
    Language: C++
    Result: Success
    Time:327 ms
    Memory:1128 kb
****************************************************************/
 
 
/*
1. 소수와 함께하는 여행
2. 소수 목록을 추출
3. 소수 목록간 그래프 구성
4. BFS 탐색을 통해서 최소 경로 탐색
5. 소수구하기 https://twpower.github.io/79-usage-of-memset-function
*/
 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
typedef struct node *pnode;
typedef struct node{
    int n;
    int step;
    pnode next;
};
typedef struct queue *pqueue;
typedef struct queue {
    int cnt;
    pnode head;
    pnode tail;
};
 
int prime_array[9999 + 1] = { 0, };
 
void enqueue(struct queue *pqueue, int N, int step) {
    //printf("enqueue: %d %d\n", N, step);
    pnode newnode = (pnode)malloc(sizeof(struct node));
    newnode->n = N;
    newnode->step = step;
    newnode->next = NULL;
    if (pqueue->cnt == 0) {
        pqueue->cnt++;
        pqueue->head = pqueue->tail = newnode;
    }
    else {
        pqueue->cnt++;
        pqueue->tail->next = newnode;
        pqueue->tail = newnode;
    }
}
void dequeue(struct queue *pqueue) {
    //printf("dequeue:\n");
    if (pqueue->cnt == 0) return;
    pnode temp = pqueue->head;
    if (pqueue->cnt == 1) {
        pqueue->head = pqueue->tail = NULL;
    }
    else {
        pqueue->head = pqueue->head->next;
    }
    pqueue->cnt--;
    free(temp);
}
int getqueue(struct queue *pqueue) {
    if (pqueue->cnt == 0) return 0;
    return pqueue->head->n;
}
 
int is_prime(int N) {
    //printf("is_prime: %d\n", N);
    if (prime_array[N] != 0) return 1;
    if (N <= 3) {
        prime_array[N] = 1;
        return 1; //true;
    }
    for (int i = 2; i*i <= 9999; i++) {
        for (int j = i; j <= 9999; j += i) {
            if (N%i == 0) return 0; //false;
        }
    }
    prime_array[N] = 1;
    return 1; //true
}
 
 
int main() {    
    int S, E;
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &S, &E);
    int prime[9999 + 1]; //0000 ~ 9999 
    //memset(prime, 0, sizeof(prime));
     
    int visited[9999 + 1] = { 0, };
     
    pqueue myqueue=(struct queue*)malloc(sizeof(struct queue));
    myqueue->cnt = 0;
    myqueue->head = NULL;
    myqueue->tail = NULL;
     
    int step = 0;
    visited[S] = step;
    enqueue(myqueue, S, step);
    int N[4] = { 0, };
     
    while (myqueue->cnt >= 1) {
        int q_num = myqueue->head->n;
        step = myqueue->head->step;
        if (q_num == E) break;
        dequeue(myqueue);
        for (int i = 0; i < 4; i++) {
            N[i]= q_num % 10;
            q_num = q_num / 10;
        }
        int sum_num;
        for (int i = 1; i <= 9; i++) {
            sum_num = i * 1000 + N[2] * 100 + N[1] * 10 + N[0];
            if (sum_num == q_num) continue;
            if (visited[sum_num] == 0 && is_prime(sum_num)) {
                visited[sum_num] = step + 1;
                enqueue(myqueue, sum_num, step + 1);
            }
        }
        for (int i = 0; i <= 9; i++) {
            sum_num = N[3] * 1000 + i * 100 + N[1] * 10 + N[0];
            if (sum_num == q_num) continue;
            if (visited[sum_num] == 0 && is_prime(sum_num)) {
                visited[sum_num] = step + 1;
                enqueue(myqueue, sum_num, step + 1);
            }
        }
        for (int i = 0; i <= 9; i++) {
            sum_num = N[3] * 1000 + N[2] * 100 + i * 10 + N[0];
            if (sum_num == q_num) continue;
            if (visited[sum_num] == 0 && is_prime(sum_num)) {
                visited[sum_num] = step + 1;
                enqueue(myqueue, sum_num, step + 1);
            }
        }
        for (int i = 0; i <= 9; i++) {
            sum_num = N[3] * 1000 + N[2] * 100 + N[1] * 10 + i;
            if (sum_num == q_num) continue;
            if (visited[sum_num] == 0 && is_prime(sum_num)) {
                visited[sum_num] = step + 1;
                enqueue(myqueue, sum_num, step + 1);
            }
        }
    }   
    printf("%d\n", myqueue->head->step);
}
