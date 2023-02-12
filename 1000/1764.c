#include <stdio.h>
int N, M;

int str_cmp(char* a, char* b) {
	int i = 0;
	while (*(a + i) != '\0' || *(b + i) != '\0') {
		if (*(a + i) < *(b + i)) return -1;
		else if (*(a + i) > *(b + i)) return 1;
		i++;
	}
	return 0;
}
void str_cpy(char* a, char* b) {
	int i = 0;
	while (*(a + i) != '\0') {
		*(b + i) = *(a + i);
		i++;
	}
	*(b + i) = '\0';
	return;
}
char list1[500000][21], list2[500000][21];
void qsort(char map[][21], int L, int R) {
	char temp[21];
	int p = L, q = R; 
	char v[21];	str_cpy(map[(L + R) / 2], v);
	while (p <= q) {
		while (str_cmp(map[p], v) < 0) p++;
		while (str_cmp(map[q], v) > 0) q--;
		if (p <= q) {
			str_cpy(map[p], temp);
			str_cpy(map[q], map[p]);
			str_cpy(temp, map[q]);
			p++; q--;
		}
	}
	if (L < q) qsort(map, L, q);
	if (R > p)qsort(map, p, R);
}
int ans[500000],cnt;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d",&N, &M);
	for (int i = 0; i < N; i++) scanf("%s", list1[i]);
	for (int i = 0; i < M; i++) scanf("%s", list2[i]);	
	qsort(list1, 0, N - 1);
	qsort(list2, 0, M - 1);
	int n = 0, m = 0, r = 0;
	while (n < N && m < M) {
		if ((r = str_cmp(list1[n], list2[m])) == 0) {
			ans[cnt++] = n;
			n++; m++;
		}
		else if (r < 0) n++;
		else if (r > 0) m++;
	}
	
	printf("%d\n", cnt);	
	for (int i = 0; i < cnt; i++) printf("%s\n", list1[ans[i]]);	
	return 0;
}