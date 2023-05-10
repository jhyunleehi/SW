#include <iostream>
#include <cstdio>
int N[6];
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    freopen("data.txt", "r", stdin);
    for (int i = 1; i <= 5; ++i)   scanf("%d", N + i);
    for (; !((N[1] == 1) && (N[2] == 2) && (N[3] == 3) && (N[4] == 4) && (N[5] == 5));) {
        for (int i = 1; i < 5; ++i) {
            if (N[i] > N[i + 1]) {
                swap(&N[i], &N[i + 1]);
                for (int j = 1; j <= 5; ++j) printf("%d ", N[j]);
                printf("\n");
            }
        }
    } 
}
