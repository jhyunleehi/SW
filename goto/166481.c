#include<stdio.h>

const int MAX_BATTERY = 100;
const int ECO_MODE = 20;

int main(void)
{
    double t, p;
    freopen("data.txt","r", stdin);
    scanf("%lf %lf", &t, &p);
    double result;
    if (p >= ECO_MODE)
    {
        double drainPerDistance = (MAX_BATTERY - p) / t;
        result = ((p - ECO_MODE) / drainPerDistance) + (ECO_MODE / (drainPerDistance / 2));
    }
    else
    {
        double drainPerDistance = ((MAX_BATTERY - ECO_MODE) + (ECO_MODE - p) * 2) / t;
        result = p / (drainPerDistance / 2);
    }
    printf("%.5lf\n", result);
    return 0;
}