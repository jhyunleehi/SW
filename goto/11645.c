#include<stdio.h>
int  T,N;
char city[101][21],str[21],cnt;
int strcmp(char*p, char *q){
	while(*p && *p == *q)   p++, q++;
  	return *p - *q;	
}
void strcpy( char *p, char *q){
	while(*p) {
		*q = *p;
		p++,q++;
	}
	*q='\0';	
}

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&T);
    while(T--){        
        scanf("%d",&N);
		cnt=0;
		for(int i = 0; i <N; i++)	{		
			scanf("%s",str);
			int hit=1;
			for (int j=0; j<cnt; j++){
				hit=strcmp(city[j],str);
				if (!hit) break;
			}
			if (hit){
				strcpy((char*)str, city[cnt]);
				cnt++;
			}
		}
		printf("%d\n", cnt);
    }
    return 0;
}