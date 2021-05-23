#include <stdio.h>
char str[11];
int  n[5];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++) {		
		int temp = str[i],k=0,sum=0;
		while (temp > 0) {
			sum+= temp % 10;
			temp = temp / 10;
		}
		for (int j = 0; j < sum; j++) printf("%c", str[i]);
		printf("\n");
	}	
	return 0;
}