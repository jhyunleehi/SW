/**************************************************************
    Problem: 1671
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
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
    int pivot = List[(left + right) / 2];
    int p = left;
    int q = right;
    do{
        while (List[p] < pivot) p++;
        while (List[q] > pivot)q--;
        if (p <= q) {
            swap(&List[p], &List[q]);
            p++; q--;
        }
    } while (p < q);
    if (left < q) qsort(List, left, q);
    if (right > p)qsort(List, p, right);
}
 
void dedup(int *List, int cnt, int* nList, int *ncnt) {
    int temp= List[0];
    int count = 1;
    nList[0] = List[0];
    //printf("\n"); for (int i = 0; i < cnt; i++) printf("[%d]", List[i]);
    for (int i = 1; i < cnt; i++) {
        if (List[i] != temp) {
            nList[count++] = List[i];
            temp= List[i];
        }
    }
    *ncnt = count;
    //printf("\n"); for (int i = 0; i < count; i++) printf("[%d]", nList[i]);
}
 
int main() {
    int P = 0;
    int pxlist[101];
    int pylist[101];
    int xlist[201];
    int ylist[201];
    int lx[201];
    int ly[201];
    int xcnt, ycnt;
    int map[201][201];
    int M[100+2][100+2] = { 0, };
    //freopen("data.txt", "r", stdin);
    scanf("%d", &P);
    for (int i = 0; i < P; i++) {
        scanf("%d %d", &pxlist[i], &pylist[i]);
        xlist[i] = pxlist[i];
        ylist[i] = pylist[i];
        xlist[i + P] = pxlist[i] + 10;
        ylist[i + P] = pylist[i] + 10;
    }
    qsort(xlist, 0, P * 2 - 1);
    qsort(ylist, 0, P * 2 - 1);
    dedup(xlist, P * 2, lx, &xcnt);
    dedup(ylist, P * 2, ly, &ycnt);
 
    //inbox check
    for (int y = 0; y < ycnt-1; y++) {
        for (int x = 0; x < xcnt-1; x++) {
            map[y][x] = 0;          
            for (int p = 0; p < P; p++) {
                //printf("%d %d %d \n", y, x, p);               
                if ((pxlist[p] <= lx[x]) && (pylist[p] <= ly[y])
                    && (pxlist[p] + 10 >= lx[x + 1]) && (pylist[p] + 10 >= ly[y + 1])) {
                    if(map[y][x]==0) map[y][x] = p+1;
                    else map[y][x] = -1;//overlay
                }               
            }
        }
    }
 
    for (int p = 0; p < P; p++) {        
        for (int y = pylist[p]; y < 10+ pylist[p]; y++) {
            for (int x = pxlist[p]; x < 10+ pxlist[p]; x++) {
                M[y+1][x+1] = 1;
            }
        }
    }
    int cnt=0;
    for (int y = 1; y <= 100; y++) {
        for (int x = 1; x <= 100; x++) {
            if (M[y][x] == 1) {
                if (M[y-1][x] == 0) cnt++;
                if (M[y+1][x] == 0) cnt++;
                if (M[y][x-1] == 0) cnt++;
                if (M[y][x+1] == 0) cnt++;
            }
        }
    }
    /*
    for (int y = 101; y >= 0; y--) {
        for (int x = 0; x <=101 ; x++) {
            printf("%d", M[y][x]);
        }
        printf("\n");
    }
    */
    printf("%d\n", cnt);
 
    return 1;
}
