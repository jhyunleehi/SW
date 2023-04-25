#include <stdio.h>
int a,b,c,x,y,z;
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d %d %d %d %d", &a,&b,&c,&x,&y,&z);    
    printf("%d %d %d",x-c,y/b,z-a);
}