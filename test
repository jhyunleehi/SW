#define _CRT_SECURE_NO_WARNING
#define MAX_X 100
#define MAX_Y 100

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>


void print_map(int map[][MAX_X], int bound_y, int bound_x) {
	for (int y = 0; y < bound_y; y++) {
		for (int x = 0; x < bound_x; x++) {
			printf("%d ", *(*(map + y) + x));
		}
		printf("\n");
	}	
}

void cal_map(int map[][MAX_X], int map_temp[][MAX_X], int bound_y, int bound_x) {
	int ky[] = { -1,-1,-1,0,0,1,1,1 };
	int kx[] = { -1,0,1,-1,1,-1,0,1 };
	int dx, dy;
	int cnt;
	int total = 0;
	for (int y = 0; y < MAX_Y; y++) {
		for (int x = 0; x < MAX_X; x++) {
			cnt = 0;
			for (int i = 0; i < 8; i++) {
				dy = y + ky[i];
				dx = x + kx[i];
				if (dx < 0)  dx = MAX_X-1;
				if (dx >= MAX_X) dx = 0;
				if (dy < 0) dy = MAX_Y-1;
				if (dy >= MAX_Y) dy = 0;
				cnt += map[dy][dx];
				total += cnt;
			}
			if ((map[y][x] == 0) && (cnt == 2)) {	
				map_temp[y][x] = 1;	
			}
			else if ((map[y][x] == 1) && (cnt >= 3) ){	
				map_temp[y][x] = 0;	
			}
			else {
				map_temp[y][x] = map[y][x];
			}
			
		}
	}
	for (int y = 0; y < MAX_Y; y++)
		for (int x = 0; x < MAX_X; x++) {
			map[y][x] = map_temp[y][x];
		}
	printf("-----------------------------------------------------[%d]\n", total);	
}



int main() {
	int map[MAX_Y][MAX_X];
	int map_cal[MAX_Y][MAX_X];
	srand(time(NULL));
	int k = 0;	
	for (int y = 0; y < MAX_Y; y++) {
		for (int x = 0; x < MAX_X; x++) {
			map[y][x] = rand() % 2;
			//map[y][x] = k++;
		}
	}
	print_map(map, MAX_Y, MAX_X);
	while (1) {
		cal_map(map,map_cal, MAX_Y, MAX_X);
		//print_map(map, MAX_Y, MAX_X);
	}

}

