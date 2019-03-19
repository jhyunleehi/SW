#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>



int main() {
	int MIN = 0x7FFFFFFF;
	int N[4] = { 0, };
	int M[4] = { 0, };
	int List[4] = { 0,0,0,0 };
	int hash[9 * 9 * 9 * 9 + 1] = { 0, };
	int temp = 0;
	int cnt = 0;
	int k = 0;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d %d", &N[0], &N[1], &N[2], &N[3]);
	for (int i = 0; i < 4; i++) {
		temp = (N[i % 4] * 1000) + (N[(i + 1) % 4] * 100) + (N[(i + 2) % 4] * 10) + (N[(i + 3) % 4]);
		List[i] = temp;
		if (temp < MIN) MIN = temp;
		//printf("min %d temp %d \n", min, temp);
	}  
	//for (int i = 0; i <= 9 * 9 * 9 * 9 + 1; i++) {hash[i] = 0;}
	//for (int i = 0; i < 4; i++) {printf("[%d] \n", List[i]);}	   
	for (int i = 1111; i <= MIN; i++) {
		k = 0;
		temp = i;
		cnt++;
		for (int j = 1000; j >= 1; j = j / 10) {
			M[k] = temp / j;
			temp = temp - M[k++] * j;
		}
		printf("[%d][%d][%d][%d]\n", M[0], M[1], M[2], M[3]);
		if ((M[0] == 0) || (M[1] == 0) || (M[2] == 0) || (M[3] == 0)) {
			printf("--[%d][%d][%d][%d]\n", M[0], M[1], M[2], M[3]);
			cnt--;
			//printf("%d\n", cnt);
			continue;
		}
		for (int m = 0; m < 4; m++) {
			if (List[m] == i) {
				printf("-[%d][%d][%d][%d]\n", M[0], M[1], M[2], M[3]);
				cnt--;
				break;
			}
		}

		temp = M[0] * M[1] * M[2] * M[3];		
		if (hash[temp] == 0) 
			hash[temp] = 1;
		else {
			printf("temp:%d\n", temp);
			cnt--;		
		}
	}
	printf("%d\n", cnt);
}
