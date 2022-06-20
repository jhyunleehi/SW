#include<stdio.h>
char str[1<<10];
int D[15];
int N;
char *p;
int getint(){
    int n=0,m=1;
    while (*p ==' ') p++;
    if (*p=='-') {m=-1;} else {n = *p-'0';}
    p++;
    while( *p  >= '0' && *p <= '9'){
        n=n*10+*p-'0';
        p++;
    }
    return n*m;
}
int main(){
    freopen("data.txt","r",stdin);
    while(fgets(str, 1<<10, stdin)){
        p=str;
        for (int i=0; *p!='\n';i++){
            D[i]=getint();
            if (D[i]==0) break;
            N=i;
        }
        if (D[0]==-1) return 0;
        int count=0;
        for (int i=0; i<=N; i++){
            for (int j=0; j<=N; j++){
                if (D[i]*2 == D[j]) {
                    count++;
                    break;
                }
            }
        }
        printf("%d\n",count);
    }
}