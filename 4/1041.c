#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int main() {
    //freopen("Text.txt", "r", stdin);
    int A, B;
    scanf("%d %d", &A, &B);
    int i(1), j;;
    while (i*i < A)  i++; 
    j = i;
    while (i*i <= B) {
        printf("%d ", i*i);
        i++;
    }
    if (j == i) printf("0");
    printf("\n");   
}
