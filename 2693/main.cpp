#include <stdio.h>
int heap[100],hcnt;
void hpush(int a) {
	hcnt++;
	int child = hcnt, parent = child / 2;
	heap[child] = a;
	while (child > 1 && heap[parent] < heap[child]) {
		int temp = heap[parent];
		heap[parent] = heap[child]; heap[child] = temp;
		child = parent;
		parent = child / 2;
	}
}

void hpop() {
	heap[1] = heap[hcnt--];
	int parent = 1, child = parent * 2;
	if (child < hcnt)
		child = (heap[child] < heap[child + 1]) ? child + 1 : child;
	while (child < hcnt && heap[parent] < heap[child]) {
		int temp = heap[parent];
		heap[parent] = heap[child]; heap[child] = temp;
		parent = child;
		child = parent * 2;
		if (child < hcnt)
			child = (heap[child] < heap[child + 1]) ? child + 1 : child;
	}
}

int T, n,a;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&T);
	while (T--) {
		n = 10; hcnt = 0;
		while (n--) {
			scanf("%d", &a);
			hpush(a);
		}
		hpop(); hpop();
		printf("%d\n", heap[1]);
	}
	
	return 0;
}