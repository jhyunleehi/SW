#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

const char *byte_to_binary(int x)
{
	static char b[9];
	b[0] = '\0';

	int z;
	for (z = 128; z > 0; z >>= 1)
	{
		strcat(b, ((x & z) == z) ? "1" : "0");
	}
	return b;
}

int main() {
	freopen("data.txt", "r", stdin);
	char *str = (char*)malloc(sizeof(char) * (32+1));
	int ip[4] = { 0, };
	int k = 0;
	scanf("%s", str);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			ip[k] = ip[k] << 1;
			ip[k]=ip[k] | (*(str++) - '0');
			//printf("%s\n", byte_to_binary(ip[k]));
		}
		k++;
	}
	k = 0;
	for (int i = 0; i < 4; i++) {
		printf("%d", ip[k++]);
		if(i<3) printf(".");
	}	
	printf("\n");
}
