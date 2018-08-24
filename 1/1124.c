/**************************************************************
    Problem: 1124
    User: jhyunlee
    Language: C++
    Result: Success
    Time:434 ms
    Memory:1292 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void qsort(int *List, int left, int right) {
    if (left >= right) return;
    int pivot = List[(left+right)/2];
    int p = left, q = right;
    do {
        while (List[p] < pivot) p++;
        while (List[q] > pivot) q--;
        if (p <=q) {
            swap(&List[p], &List[q]);
            p++; q--;
        }
    } while (p <= q);
    if( left< q) qsort(List, left, q);
    if(right>p) qsort(List, p, right);
}
 
void dedup(int *List, int N, int *lx, int *cnt) {
    int temp = List[0];
    *cnt = 1;
    lx[0] = List[0];
    for (int i = 1; i <= N; i++) {
        if (temp != List[i]) {
            temp = List[i];
            lx[(*cnt)++] = List[i];         
        }
    }
    //printf("%d \n", *cnt);
}
 
int main() {
 
    int Paper = 0;
    int paperx[101] = { 0, };
    int papery[101] = { 0, };
    int listx[200 + 1] = { 0, };
    int listy[200 + 1] = { 0, };
    int lx[200 + 1] = { 0, };
    int ly[200 + 1] = { 0, };
    int map[201][201] = { 0, };
    int result[201][201] = { 0, };
     
    //freopen("data.txt", "r", stdin);
    scanf("%d", &Paper);
    for (int i = 0; i < Paper; i++) {
        scanf("%d %d", &paperx[i], &papery[i]);
        listx[i] = paperx[i];
        listy[i] = papery[i];
        listx[i + Paper] = listx[i] + 10;
        listy[i + Paper] = listy[i] + 10;
    }
    //for (int i = 0; i < Paper*2; i++)  printf("[%d] ", listx[i]); printf("\n");
    //for (int i = 0; i < Paper*2; i++)  printf("[%d] ", listy[i]); printf("\n");
     
    qsort(listx, 0, Paper * 2 - 1);
    qsort(listy, 0, Paper * 2 - 1);
    //for (int i = 0; i < Paper * 2; i++)  printf("[%d] ", listx[i]); printf("\n");
    //for (int i = 0; i < Paper * 2; i++)  printf("[%d] ", listy[i]); printf("\n");
     
    int cntx = 0;
    int cnty = 0;
    dedup(listx, Paper * 2 - 1, lx, &cntx);
    dedup(listy, Paper * 2 - 1, ly, &cnty);
    //for (int i = 0; i < cntx; i++)  printf("[%d] ", lx[i]); printf("\n");
    //for (int i = 0; i < cnty; i++)  printf("[%d] ", ly[i]); printf("\n");
    //cntx, xnty is number of line
     
    int boxx = cntx - 1;
    int boxy = cnty - 1;
    for (int y = 0; y < boxy; y++) {
        for (int x = 0; x < boxx; x++) {
            //printf("%d %d\n", x, y);
            map[y][x] = 0;
            for (int k = 0; k < Paper; k++) {
                if ((paperx[k] <= lx[x]) && (papery[k] <= ly[y]) &&
                    (paperx[k] + 10 >= lx[x + 1]) && (papery[k] + 10 >= ly[y + 1])) {
                    map[y][x] = (lx[x + 1] - lx[x])*(ly[y + 1] - ly[y]);
                    //map[y][x] = 1;
                    break;
                }
            }
        }
    }
 
    int maxsize = 0;
    for (int y = 0; y<boxy ; y++) {
        for (int x = 0; x<boxx ; x++) {                          
            for (int i = y; i < boxy; i++) {
                for(int j=x; j < boxx; j++){
                    bool outbox = false;
                    int  sum = 0;
                    for (int r1 = y; r1 <= i; r1++) {
                        for (int r2 = x; r2 <= j; r2++) {                            
                            if (map[r1][r2] == 0) {
                                outbox = true;
                                sum = 0;
                                break;
                            }
                            sum = sum + map[r1][r2];
                            //printf("    %d %d %d %d %d \n", i, j, r1, r2, sum);
                        }
                        if (outbox) break;
                    }
                    if ((!outbox) && (result[y][x] < sum)) {
                        result[y][x] = sum;
                        if (maxsize <= sum) maxsize = sum;
                    }                   
                }
                 
            }
 
        }
    }
    
    printf("%d\n", maxsize);
    return 1;
}
