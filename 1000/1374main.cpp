#include <stdio.h>
char str[1000001];
int size,temp,cnt;
char ans[20];
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%s",str);
	while (str[size] != '\0')  size++ ;
	int s = 0;
	for (int i = (size-1); i >= 0; i--) {
		temp=temp|((str[i] - '0') <<s);
		s++;
		if ((s % 3 == 0)||(i==0)) {
			s = 0;			
			ans[cnt++] = temp + '0';
			temp = 0;
		}
	}
	for (int i = cnt - 1; i >= 0; i--) printf("%c", ans[i]);
	printf("\n");
	return 0;
}