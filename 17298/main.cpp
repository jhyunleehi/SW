#include <stdio.h>
int N; //1,000,000
int A[10 + 2];
int R[10 + 2];
int S[10 + 1],top;

char rbuffer[1 << 20];

char getByte() {
	static int bidx = -1;
	if (bidx == -1) {
		fread(rbuffer, 1, 1 << 20, stdin);
		bidx = 0;
	}
	if (bidx == 1 << 20) {
		fread(rbuffer, 1, 1 << 20, stdin);
		bidx = 0;
	}
	return rbuffer[bidx++];
}

int getInt() {
	int temp = 0, minus = 0;
	char ch;
	while ((ch = getByte()) == '\n');
	if (ch == '-1') minus = -1;
	else temp = ch - '0';
	while ((ch = getByte()) >= '0' && ch <= '9') {
		temp = (temp << 3) + (temp << 1) + (ch - '0');
	}
	return (minus == -1) ? temp * -1 : temp;
}
void push(int a) {
	S[++top] = a;
}
int pop() {	
	if (top >= 1)	
		return S[top--];
	else 
		return - 1;
}
int getTop() {
	if (top >= 1)
		return S[top];
	else
		return -1;
}


int main() {
	freopen("data.txt","r", stdin);
	scanf("%d",&N);
	for (int i = 0; i < N; i++) A[i] = getInt();
		
	for (int i = 0; i < N-1; i++) {
		push(i);
		while (top >= 1 && A[getTop()] < A[i + 1]) {
			int temp = pop();
			R[temp] = A[i + 1];			
		}
	}
	push(N-1);
	while (top >= 1) {
		int temp = pop();
		R[temp] = -1;
	}	
	for (int i = 0; i < N; i++) printf("%d ",R[i]); 
	printf("\n");

	return 0;
}