#include<stdio.h>
#include<malloc.h>

int main() {
	int A, B, C,D, E,F;
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &A, &B);

	int min1 = 0x7FFFFFFF;
	int min2 = 0x7FFFFFFF;	
	int TA = A, TB = B;
	for (int i = 1; A*i <= B; i++) {
		if (B % (A*i) == 0) {
			C = A * i;
			D = B / (A*i)*A ;
			if (min1 > C + D) {
				min1 = C + D;
				E = C;
				F = D;
			}
			//printf("%d  %d  %d  %d %d\n", i, A*i, B/(A*i)*A, C*D, C+D);
		}		
		//printf("%d  %d  %d \n", i, C, i*C);
	}

	//printf("%d %du\n", min1, min2);
	printf("%d %d\n", (E<F)? E:F, (E<F) ? F:E);
	return 1;
}
