#define _CRT_SECURE_NO_WARNINGS
#define _MAX_A 1000
#define _MAX_B 4000
 
#include<stdio.h>
#include<malloc.h>
 
int main () { 
    int x=0, y=0;
    int a, b, c;    
    //freopen("input.dat", "r", stdin);
    while (true) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        if ((a == 0) && (b == 0)) break;
        if ((a > _MAX_A) || (a < 0) || (b > _MAX_B) || (b < 0)) {
            printf("INPUT ERROR!\n");
            continue;
        }       
        c = (b - 2 * a);
        x = (b - 2 * a) / 2;
        y = a - x;
        if (((c % 2) != 0 ) || (x < 0)||(y < 0) ){
            printf("%d\n", x = 0);
            continue;
        }
         
        printf("%d %d\n", x, y);
    }
}
