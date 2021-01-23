#include<cstdio>
 
void swap(unsigned char *a, unsigned char *b) {
    unsigned  char temp(*a);
    *a = *b; *b = temp;
}
void quick_sort(unsigned char M[], int s, int e) {
    //printf("quick_sort: %s*\n", M);
    if (s >= e) return;
    int v = M[(s + e) / 2];
    int p = s, q = e;
    while (p <= q) {
        while (M[p] < v) p++;
        while (M[q] > v)q--;
        if (p <= q) {
            swap(&M[p], &M[q]);
            p++; q--;
        }
    }
    if (s < q) quick_sort(M, s, q);
    if (e > p) quick_sort(M, p, e);
}
 
void reset_order(unsigned char M[], int size) {
    //printf("reset_order: [%s]\n", M);
    int i(1);
    while ((M[0] < M[i]) && (i < size)) { i++; }
    if (i == size)  swap(&M[0], &M[size - 1]);
    else swap(&M[0], &M[i-1]);
 
    quick_sort(M, 1, size - 1);
}
 
int main() {
    //freopen("data.txt", "r", stdin);
    unsigned char M[100 + 1];
    int size(0);
    scanf("%s", M);
    while (*(M + size) != '\0') { size++; };
    //printf("%d\n", size);
    int run(1);
    int change(0);
    int end = size - 1;
    while (run) {
        change = 0;
        int i;
        int MIN = 0x7FFFFFFF;
        int pos = 0;
        for (i = end -1; i >= 1; i--) {
            for (int j = i +1; j <= end; j++) {
                if (M[i] < M[j]) {
                    if ((M[j] - M[i]) < MIN) {
                        MIN = M[j] - M[i];
                        pos = j;
                    }
                }           
            }                   
            if (pos != 0) {
                swap(&M[i], &M[pos]);
                quick_sort(M, i + 1, end);
                change = 1;
                break;
            }
        }
         
        if ((change == 0)) {
            if (M[0] < M[1]) {
                reset_order(M, size);
            }
        }
        for (i = 0; i < size - 1; i++) {
            if (M[i] < M[i + 1]) {
                run = 1;
                break;
            }
        }
        printf("%s\n", M);
        if (i == size - 1) run = 0;
        run = 0;
    }
 
}
