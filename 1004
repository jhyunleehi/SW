#define _CRT_SECURE_NO_WARNINGS
 
#include<stdio.h>
#include<malloc.h>
#include<math.h>
 
int main() {
    int cnt;
    int sum=0;
    double avg;
    double dev;
    //freopen("input.dat", "r", stdin);
    scanf("%d", &cnt);
    int *num = (int*)malloc(sizeof(int)*(cnt + 1));
    for (int i = 0; i < cnt; i++) {
        scanf("%d", (num + i));
        sum += *(num + i);      
    }
     
    avg = floor((sum*1.0 / cnt*1.0) * 10.0 + 0.5) / 10.0;
 
    double ss=0;
    for (int i = 0; i < cnt; i++) {
        ss += (*(num + i) - avg)*(*(num + i) - avg);
    }
    dev = floor ((sqrt((ss*1.0)/(cnt*1.0)) * 10.0) + 0.5) / 10.0;
    printf("%d\n", sum);
    int temp = ((int)(avg * 10)) % 10;
    if (temp == 0)
        printf("%.f\n", avg);
    else
        printf("%.1f\n", avg);
    temp = ((int)(dev * 10)) % 10;
    if (temp == 0)
        printf("%.f\n", dev);
    else
        printf("%.1f\n", dev);
    return 0;
}
