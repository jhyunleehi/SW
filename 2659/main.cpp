#include <stdio.h>
int map[9999 + 1];
int clock[9999];
int in[4], t[4];
int count;
void checkc() {
	for (int n = 1111; n <= 9999; n++) {
		if (map[n] == 0) {			
			clock[count++] = n;
			int temp = n;
			for (int j = 0; j < 4; j++) {
				t[3-j] = temp % 10;
				temp = temp / 10;
			}
			for (int k = 0; k < 4; k++) {
				int num = t[k % 4] * 1000 + t[(k + 1) % 4] * 100 + t[(k + 2) % 4] * 10 + t[(k + 3) % 4];
				map[num] = 1;
				//printf("[%d] [%d] %d %d %d %d \n ",n, num,  t[0], t[1], t[2], t[3]);
			}			
		}
	}
}
int temp;
void checkz() {
	for (int n = 1111; n <= 9999; n++) {
		temp = n;
		for (int j = 0; j < 3; j++) {
			if ((temp % 10) == 0) {
				map[n] = 1;
				break;
			}
			temp = temp / 10;
		}
	}
}

int getclocknum() {
	int temp = 0x7FFFFFFF;
	for (int k = 0; k < 4; k++) {
		int num = in[k % 4] * 1000 + in[(k + 1) % 4] * 100 + in[(k + 2) % 4] * 10 + in[(k + 3) % 4];
		temp = (temp > num) ? num : temp;
	}
	return temp;
}

int bsearch(int L, int R, int num) {
	while (L <= R) {
		int mid = (L + R) / 2;
		if (clock[mid] == num) return mid;
		else {
			if (clock[mid] > num) 
				R = mid - 1;
			else
				L = mid + 1;
		}
	}
	return 0;
}

int ans;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d", &in[0], &in[1], &in[2], &in[3]);
	int num = in[0] * 1000 + in[1] * 100 + in[2] * 10 + in[3];
	checkz();
	checkc();
	int cnum = getclocknum();
	ans = bsearch(0, count, cnum);
	printf("%d\n", ans+1);
	return 0;
}