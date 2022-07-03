#include <stdio.h>
#define PI 3.141592653589793238462643383279502884L 
double a[2], p[2], t[2];
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%lf %lf", &a[0], &p[0]);
    t[0] = a[0] / p[0];
    scanf("%lf %lf", &a[1], &p[1]);
    t[1] = (a[1] * a[1] * PI) / p[1];
    if (t[0] < t[1])
        printf("Whole pizza\n");
    else
        printf("Slice of pizza\n");
}
