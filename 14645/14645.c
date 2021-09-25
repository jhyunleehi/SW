#include <stdio.h>
int n,u,d,to;
int main(){
    scanf("%d%d",&n,&u);
    for(int i=0; i<n; i++){
        to+=u;
        scanf("%d%d",&u,&d);
        to+=u;to-=d;
    }
    printf("비와이\n");
    return 0;
}