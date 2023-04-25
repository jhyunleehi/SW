#include<stdio.h>
int N;
int main (){
    freopen("data.txt","r",stdin);
    while(1){
    scanf("%d",&N);
        if (N == -1) return 0;
        int mile=0;
        int s=0,h=0,p=0;
        while (N--) {
            scanf("%d %d", &s, &h);
            mile += s * (h - p);
            p=h;
        }
        printf("%d miles\n", mile);        
    }
}