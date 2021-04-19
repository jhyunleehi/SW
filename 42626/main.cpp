#include <stdio.h>
#include<vector>
using namespace std;
int sco[1000001];
int scocnt;
void hpush(int n) {
	sco[++scocnt] = n;
	int c = scocnt;
	int p = c / 2;
	while (c > 1 && sco[c] < sco[p]) {
		int temp = sco[c];
		sco[c] = sco[p]; sco[p] = temp;
		c = p; p = c / 2;
	}
}

void hpop() {
	sco[1] = sco[scocnt]; sco[scocnt] = 0; scocnt--;
	int p = 1;
	int c = p * 2;
	if (scocnt > c)  c = (sco[c] < sco[c + 1]) ? c : c + 1;
	while (c <= scocnt && sco[c] < sco[p]) {
		int temp = sco[c];
		sco[c] = sco[p]; sco[p] = temp;
		p = c; c = p * 2;
		if (scocnt > c) c = (sco[c] < sco[c + 1]) ? c : c + 1;
	}
}

int solution(vector<int> scoville, int k) {
	int a = 0, b = 0, c = 0, ans = 0;;
	for (int v : scoville) hpush(v);
	while (1) {
		if (scocnt <= 1 && sco[1] < k)  printf("-1\n");
		if (scocnt <= 1 && sco[1] >= k) printf("%d\n",ans);
		a = sco[1]; hpop();
		b = sco[1]; hpop();
		if (a >= k && b >= k) {
			printf("%d\n", ans);
			return 0;
		}
		c = a + (b * 2);
		hpush(c);
		ans++;
	}
}


int main() {
	vector <int> v1{ 1, 2, 3, 9, 10, 12 };
	int k = 7;
	solution(v1, k);
	return 0;
}