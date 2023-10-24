#include <stdio.h>

char str[1<<10];
int N;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%s %d",str,&N);
    printf("%c",str[N-1]);
}