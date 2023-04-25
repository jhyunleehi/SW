#include <stdio.h>
int N, A, x, y, cnt = 1;

char data[10][8] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

int strcmp(const char *p, const char *q)
{
    while (*p && *p == *q)
        p++, q++;
    return *p - *q;
}

int getv(char *a)
{
    int k = -1;
    for (int j = 0; j < 10; j++)
    {
        if (strcmp(data[j], a) == 0)
        {
            return j;
        }
    }
    return k;
}

long long getpow (int a, int b){
    long long temp=1;
    for (int i=0; i<b; i++){
        temp=temp*a;
    }
    return temp;
}
char str[3][8];
int main()
{
    freopen("data.txt", "r", stdin);
    for (int i = 0; i < 3; i++)
        scanf("%s", str[i]);
    int a = getv(str[0]);
    int b = getv(str[1]);
    int c = a*10 +b;
    int d = getv(str[2]);
    long long e=getpow(10,d);

    printf("%lld\n", c*e );
}
