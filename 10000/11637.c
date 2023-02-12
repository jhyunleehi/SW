#include<stdio.h>
int  T,member,in;

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        int n, sum = 0, num = 0, max = 1, idx = 1;
        scanf("%d",&member);
		for(int i = 1; i <=member; i++)	{		
			scanf("%d",&in);
			sum+= in;
			if(max < in) {
				max = in;num = 1;idx = i;
			}
			else if(max == in) num++; 
		}
		if(num > 1) printf("no winner\n");
		else {
			if(max > sum/2) printf("majority winner %d\n",idx);
			else printf("minority winner %d\n",idx);
		}
    }
    return 0;
}