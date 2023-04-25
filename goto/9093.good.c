#include <stdio.h>
#include <string.h>

char ori[1001], str[1001];

int main(){
	int t;
	scanf("%d ",&t);
	while (t--){
		gets(ori);
		int start = 0;
		int L = strlen(ori);
		for (int i=0; i<=L; i++){
			if (ori[i] == ' '|| ori[i] == '\0'){
				int end = i-1;
				for (int j=start; j<i; j++, start++){
					str[start] = ori[end];
					end = end - 1;
				}
				str[start] = ori[start];
				start ++;
			}
		}
		printf("%s\n",str);
	}
}