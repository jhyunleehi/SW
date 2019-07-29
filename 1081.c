#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<ctime>
typedef struct node *pnode;
typedef struct node {
	int P;
	int L, R;
	int C;
	int pos;
	
};
node Map[2000 + 2];
int  W[1000][2] = { 0, };
void chk_tree_p(int node, int target, int key) {
	if (node == target) return;
	if ((Map[node].L > 0  ) && (Map[node].L != target)) {
		if (Map[Map[node].L].pos >= key) Map[Map[node].L].pos += 1;
		chk_tree_p(Map[node].L, target, key);
	}
	if ((Map[node].R > 0 ) && (Map[node].R != target)) {
		if (Map[Map[node].R].pos >= key) Map[Map[node].R].pos += 1;
		chk_tree_p(Map[node].R, target, key);
	}
}

void chk_tree_n(int node, int target, int key) {
	if (node == target) return;
	if ((Map[node].L > 0  )  && (Map[node].L != target )) {
		if (Map[Map[node].L].pos <= key) Map[Map[node].L].pos -= 1;
		chk_tree_n(Map[node].L, target, key);
	}
	if ((Map[node].R > 0 ) && (Map[node].R != target)) {
		if (Map[Map[node].R].pos <= key)Map[Map[node].R].pos -= 1;
		chk_tree_n(Map[node].R, target, key);
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	int cnt;
	int N(0), R(0), L(0);
	scanf("%d", &cnt);	
	Map[1].P = -1;
	Map[1].C = 1;
	Map[1].pos = 0;
	W[1][0] = 0;
	W[1][1] = 0;
	for (int i = 0; i < cnt; i++) {
		scanf("%d %d %d", &N, &L, &R);
		Map[N].L = L;
		Map[N].R = R;
		if (L != -1) {
			Map[L].P = N;
			Map[L].C = Map[N].C + 1;			
			if (Map[N].pos > 0) {
				Map[L].pos = Map[N].pos;
				chk_tree_p(1, L, Map[L].pos);
			}
			else {
				Map[L].pos = Map[N].pos-1;
				chk_tree_n(1, L, Map[L].pos);
			}

		}
		if (R != -1) {
			Map[R].P = N;
			Map[R].C = Map[N].C + 1;						
			if (Map[N].pos >= 0) {
				Map[R].pos = Map[N].pos + 1;
				chk_tree_p(1, R, Map[R].pos);
			}
			else {
				Map[R].pos = Map[N].pos ;
				chk_tree_n(1, R, Map[R].pos);
			}
		}			
		
	}

	int c;
	for (int i = 1; i <= cnt; i++) {
		c = Map[i].C;
		if (W[c][0] > Map[i].pos) W[c][0] = Map[i].pos;
		if (W[c][1] < Map[i].pos) W[c][1] = Map[i].pos;
	}

}
