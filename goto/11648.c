#include<stdio.h>
int  N,i;
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&N);
    for (i=0;N>=10;i++){
		int temp=1;
		while (N>0){
			temp*=(N%10);
			N=N/10;
		}
		N=temp;
	}
	printf("%d",i);
    return 0;
}