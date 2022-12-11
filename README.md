# Code

## Read

#### fread(), getbyte(), getInt(), dfs()

- 1<<20 512KB 단위로 읽어오는 것
- 읽어온 데이터 데이터 버퍼에서 원하는 만큼 char 단위로 읽어 와서 integer 변환
- dfs 구현

```c
#include<stdio.h>
char rbuf[1 << 20];
int map[101];
int visit[101];
int result[101];
int N,count;

void read() {
	fread(rbuf, 1, 1 << 20, stdin);
}
char getByte() {
	static int bidx = -1;
	if (bidx == -1) {
		read();
		bidx = 0;
	}
	if (bidx == 1 << 20) {
		read();
		bidx = 0;
	}
	return rbuf[bidx++];
}

int getInt() {
	int temp=0, minus=0;
	char ch = getByte();
	if (ch == '-') minus = -1;
	else temp = ch - '0';
	while ((ch = getByte()) >= '0' && ch <= '9') {
		temp = (temp << 3) + (temp << 1) + (ch - '0');
	}
	return (minus == -1) ? temp * -1 : temp;
}

bool dfs(int s, int n) {
	//printf("[%d][%d]\n", s, n);
	visit[n] = 1;
	if (map[n] == s) return true;

	if (visit[map[n]] == 0) {
		if (dfs(s, map[n])) return true;
		else return false;
	}
	return false;
}
void chk(int n) {
	visit[n] =1;
	result[n] = 1;
	if (visit[map[n]] == 0) {
		chk(map[n]);
	}
}
int main() {
	int i = 0, j = 0;;
	freopen("data.txt", "r", stdin);
	N = getInt();
	for (i =1; i <= N; i++) map[i] = getInt();
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) visit[j] = 0;
		if (dfs(i, i) == true) {
			for (j = 1; j <= N; j++) visit[j] = 0;
			chk(i);
		}
	}
	for (i = 0; i <= N; i++) if (result[i] == 1) count++;
	printf("%d\n", count);
	for (i = 0; i <= N; i++) {
		if (result[i] == 1) printf("%d\n", i);
	}
}
```
### getInt()
```c
#include <stdio.h>
char rbuf[1 << 10];
int sum;

void readrbuf() {
	fread(rbuf, 1, 1 << 10, stdin);
}
char getbyte() {
	static int bidx = -1;
	if (bidx == -1) { readrbuf(); bidx = 0;}
	if (bidx == 1 << 20) {readrbuf(); bidx = 0;}	
	return rbuf[bidx++];
}

int getInt() {
	int temp = 0;
	char ch = getbyte();
	if (ch == '\0') return EOF;
	temp = ch - '0';
	while ((ch = getbyte()) >= '0' && (ch <= '9')) {		
		temp = (temp *10) + (ch - '0');
	}
	return temp;
}

int main() {
	freopen("data.txt", "r", stdin);		
	int num = 0;
	while ((num = getInt()) != EOF) {
		sum += num;		
	}
	printf("%d\n", sum);	
	return 0;
}
```

#### buffered read()

```c
#include<stdio.h>

int N;
char str[101];
char *p;
int size;
int  main(void) {
	freopen("data.txt", "r", stdin);
	fread(str, 1, 101, stdin);
	p = str;
	for (int i = 0; *(p + i) != '\0'; i++) {
		if ((*(p + i) >= 'A') && (*(p + i) <= 'Z')  ) {
			printf("%c", ((*(p + i) - 'A') +13) % 26 + 'A');
		}
		else if ((*(p + i) >= 'a') && (*(p + i) <= 'z')) {
			printf("%c", ((*(p + i) - 'a') +13) % 26 + 'a');
		}
		else {
			printf("%c", *(p + i));
		}
	}
	printf("\n");
	return 0;
}
```

### read line

- fget `\n` 또는 EOF를 만날 때까지 읽어서 char \* return 한다.
- return 되는 char\* 에 '\n'이 포함되어 있기 때문에 비교할때 주의

```c
#include <stdio.h>
char instr[1 << 10];
char str[30];
const char *msg1 = "고무오리 디버깅 시작" ;
const char *msg2 = "문제";
const char *msg3 = "고무오리";
const char *msg4 = "고무오리 디버깅 끝";

int strCmp(const char* src, char* dest) {
	while (1) {
		if (*src != *dest) return (*src < *dest) ? -1 : 1;
		if (!*src) break;
		src++; dest++;
	}
	return 0;
}
void strTrim(char* str) {
	while (*str != '\0') {
		if (*str == '\n') *str = '\0';
		str++;
	}
}

int main() {
	int problem = 0;
	freopen("data.txt", "r", stdin);
	while (fgets(instr, 1<<10, stdin)) {
		strTrim(instr);
		if (!strCmp(msg1, instr)) {
			problem = 0;
		}
		else if (!strCmp(msg4, instr)) {
			if (problem == 0) printf("고무오리야 사랑해\n");
			else printf("힝구\n");
			break;
		}
		else if (!strCmp(msg2, instr)) {
			problem++;
		}
		else if (!strCmp(msg3, instr)) {
			if (problem <= 0) problem += 2;
			else problem--;
		}

	}

}
```

## 수학

- 약수: 약수는 어떤 수를 나머지 없이 나눌 수 있는 정수입니다.
  1, 3, 5, 15는 15를 나머지 없이 나눌 수 있기 때문에, 15의 약수입니다.
- 소수: 자기 자신과 1로만 나눌 수 있는 수입니다.

### GCD

```c
int get_gcd(int A, int B) {
    if (A < B) {
        int temp = B;
        B = A;
        A = temp;
    }
    while (A%B != 0) {
        A = A % B;
        int temp = A;
        A = B; B = temp;
    }   
    //printf("[%d]\n", B);
    return B;
}
``` 


### 에라토스테네스의 체

- 고대 그리스의 수학자 에라토스테네스가 만들어 낸 소수를 찾는 방법. 이 방법은 마치 체로 치듯이 수를 걸러낸다

```c
#include<stdio.h>

char s[10001] = { 1,1, };
int m, n;
int min = 0x7fffffff;
int sum;
int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d", &m);
	scanf("%d", &n);
	for (int i = 2; i*i <= n; i++) {
		if ( s[i] == 0)
			for (int j = i + i; j <= n; j=j + i)
			s[j] = 1;
	}
	for (int i = m; i <= n; i++) {
		if (s[i] == 0) {
			min = (min > i) ? i : min;
			sum += i;
		}
	}
	if (sum == 0)printf("-1\n");
	else printf("%d\n%d\n", sum, min);
	return 0;
}

```



## string

### strcmp strcpy

- xv6 string copy, comp

```c
char* strcpy(char *s, const char *t){
  char *os;
  os = s;
  while((*s++ = *t++) != 0);
  return os;
}

int strcmp(const char *p, const char *q){
  while(*p && *p == *q)   p++, q++;
  return (uchar)*p - (uchar)*q;
}
```

### strcmp

```c
void strcpy(const char *a, char *b) {
	int i = 0;
	while (*(a + i) != '\0') {
		*(b + i) = *(a + i);
		i++;
	}
	*(b + i) = '\0';
}

int strcmp(const char *a, const char *b) {
	int i = 0;
	while ((*(a + i) != '\0') || (*(b + i) != '\0')){
		if (*(a + i) < *(b + i)) return -1;
		if (*(a + i) > *(b + i)) return 1;
	i++;
	}
	return 0;
}
```

#### string sort

```c
#include <stdio.h>
#include<malloc.h>
char* nstr[10];
char* mstr[20];
int N, M;

int strcmp(char* p, char* q) {
	while (*p && *p == *q) 	p++, q++;
	return *p - *q;
}

void qsort(char* nstr[], int L, int R) {
	char* m = nstr[(L + R) / 2];
	int p = L, q = R;
	while (p < q) {
		while (strcmp(m, nstr[p]) > 0) p++;
		while (strcmp(m, nstr[q]) < 0) q--;
		if (p <= q) {
			char* temp = nstr[p];
			nstr[p] = nstr[q];
			nstr[q] = temp;
			p++; q--;
		}
	}
	if (L < q) qsort(nstr, L, q);
	if (p < R) qsort(nstr, p, R);
}

int bsearch(int p, int q, char* s) {
	while (p <= q) {
		int mid = (p + q) / 2;
		int t = strcmp(s,nstr[mid]);
		if (t == 0)
			return mid;
		else if (t < 0)
			q = mid - 1;
		else if (t > 0)
			p = mid + 1;
	}
	return -1;
}

int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		char* str = (char*)malloc(sizeof(char) * 501);
		scanf("%s", str);
		nstr[i] = str;
	}
	for (int i = 0; i < M; i++) {
		char* str = (char*)malloc(sizeof(char) * 501);
		scanf("%s", str);
		mstr[i] = str;
	}
	qsort(nstr, 0, N - 1);
	//for (int i = 0; i < N; i++)	printf("%s\n", nstr[i]);
	int count = 0;
	for (int i = 0; i < M; i++) {
		if (-1 != bsearch(0, N - 1, mstr[i])) {
			//printf("%s\n", mstr[i]);
			count++;
		}
	}
	printf("%d\n", count);
}
```


## stack

```c
#include<stdio.h>

int N;
int s[100001];
int top=0;
int cnt=1;
int t;
char M[200100];
int  idx = 1;
void push(int n) {
	s[++top] = n;
}
int pop() {
	if (top >=1) return s[--top];
	else return  -1;
}
int main() {
	int v = 1;
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	while(N--){
		scanf("%d", &t);
		while (s[top] < t) {
			if (s[top] < t) {
				push(cnt++);
				M[idx++] = '+';
			}
		}
		if (s[top] == t) {
			M[idx++] = '-';
			if (pop() == -1) v = 0;
		}
		else {
			v = 0;
		}
	}
	if (v)	for (int i = 1; i < idx; i++) printf("%c\n", M[i]);
	else printf("NO");
	return 0;
}

```

## Linked List

### linked List

```c
#include <stdio.h>
#include <malloc.h>

typedef struct node *pnode;
typedef struct node {
	int n;
	pnode next;
	pnode pre;
};

pnode head;
pnode tail;
int count;

int n, k;

void add(int i) {
	pnode temp = (pnode)malloc(sizeof(struct node));
	count++;
	temp->n = i;
	temp->next = head;
	temp->pre = tail;
	if (tail == NULL) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
		tail->next->pre = temp;
	}
}

void get(int k) {

	if (count <= 0) return;
	for (int i = 1; i <= k - 1; i++) {
		head = head->next;
	}
	if (count > 1)	printf("%d, ", head->n );
	else {
		printf("%d", head->n);
		return;
	}
	head->pre->next = head->next;
	head->next->pre = head->pre;
	pnode  temp = head;
	head = head->next;
	free(temp);
	count--;
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		add(i);
	}
	printf("<");
	for (int i = 1; i <= n; i++) {
		get(k);
	}
	printf(">");
	return 0;
}
```

#### 인접행렬 (adjacency matrix)
```c
#include<stdio.h>
#include<stdlib.h>

int N, M, V;

char map[1001][1001];


int vmap[1001];
void dfs(int n) {
	printf("%d ", n);
	vmap[n] = 1;
	//if (list[n] == NULL) return;
	for (int i = 1; i <= N; i++) {
		if ((map[n][i] == 1) && (vmap[i] == 0)) {
			dfs(i);
		}
	}
}

int v[1001];
int q[1001];
int qh, qr;
void bfs(int n) {
	v[n] = 1;
	q[qh++] = n;
	while (qh > qr) {
		n = q[qr++];
		printf("%d ", n);
		for (int i = 1; i <= N; i++) {
			if ((map[n][i] ==1)&& (v[i] == 0)) {
				v[i] = 1; //visited 
				q[qh++] = i;
			}
		}		
	}
}

int main() {
	int a, b;
	//freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &N,&M,&V);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		//addnode(a, b);
		//addnode(b, a);
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(V);
	printf("\n");
	bfs(V);
	
	return 0;
}


```
#### 인접리스트 (adjacency list)
```c
#include<stdio.h>
#include<stdlib.h>

int N, M, V;

char map[1001][1001];

typedef struct node *pnode;
typedef struct node {
	int n;
	pnode next;
};

struct node *list[1001];
void addnode(int from, int to) {
	if (list[from] == NULL) {
		pnode temp=(struct node*)malloc(sizeof(struct node));
		temp->n = to;
		temp->next = NULL;
		list[from] = temp;
	}else {
		pnode temp = list[from];
		while (temp->next != NULL) {
			temp = temp->next;
		}
		pnode nNode = (struct node*)malloc(sizeof(struct node));
		nNode->n = to;
		nNode->next = NULL;
		temp->next = nNode;
	}
}

int vmap[1001];
void dfs(int n) {
	printf("%d ", n);
	vmap[n] = 1;
	if (list[n] == NULL) return;
	pnode temp = list[n];
	while (temp != NULL) {
		if (vmap[temp->n] != 1) dfs(temp->n);
		temp = temp->next;
	}
}
int v[1001];
int q[1001];
int qh, qr;
void bfs(int n) {
	v[n] = 1;
	q[qh++] = n;
	while (qh > qr) {
		n = q[qr++];
		printf("%d ", n);
		pnode temp = list[n];
		while (temp != NULL) {
			if (v[temp->n] == 0) {
				v[temp->n] = 1;
				q[qh++] = temp->n;
			}
			temp = temp->next;
		}
	}
}

int main() {
	int a, b;
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &N,&M,&V);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		addnode(a, b);
		addnode(b, a);
		//map[a][b] = 1;
		//map[b][a] = 1;
	}
	dfs(V);
	printf("\n");
	bfs(V);
	
	return 0;
}

```


## Sort

### quick sort

```c
#include <stdio.h>
int N;
typedef struct person *pperson;
typedef struct person {
	char name [16];
	int  birth;
};
struct person ps[101];
int d, m, y;
void qsort(int L, int R) {
	int p = L,q = R, v=ps[(p + q) / 2].birth;
	while (p <= q) {
		while (v > ps[p].birth)p++;
		while (v < ps[q].birth)q--;
		if (p <= q) {
			struct person temp = ps[p];
			ps[p] = ps[q];
			ps[q] = temp;
			p++; q--;
		}
	}
	if (L < q) qsort(L, q);
	if (p < R)qsort(p, R);
}
int main() {
	scanf("%d" , &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", ps[i].name, &d, &m, &y);
		ps[i].birth = y * 10000 + m * 100 + d;
	}
	qsort(0, N - 1);
	printf("%s\n", ps[N - 1].name);
	printf("%s\n", ps[0].name);
	return 0;
}
```
### string 포함된 배열 qsort

```c
#include <stdio.h>
typedef struct item {
    char name[21];
    int w;
};
struct item data[101];
int T,N;
void qsort(int L, int R){
    int p=L,q=R,v=data[(L+R)/2].w;
    while(p<q){
        while(v < data[p].w) p++;
        while(v > data[q].w) q--;
        if (p<=q){
            struct item temp = data[p];
            data[p] = data[q];
            data[q] = temp;
            p++; q--;
        }
    }
    if (q>L) qsort(L,q);
    if (p<R) qsort(p,R);
}

int main(){
    freopen("data.txt", "r", stdin);
    scanf("%d",&T);        
    for (int i = T; i; i--){
        scanf("%d", &N);
        for (int j=0; j<N; j++) scanf("%s %d", data[j].name,&data[j].w);     
        qsort(0,N-1);
        printf("%s\n",data[0].name);
    }     
}
```




## 이분탐색

### qsort, bsearch

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, M;
int n[100000 + 1];
int m[100000 + 1];
int max;
void qsort(int map[], int L, int R) {
	int p = L;
	int q = R;
	int v = map[(p + q) / 2];
	while (p <= q) {
		while (v > map[p])p++;
		while (v < map[q])q--;
		if (p <= q) {
			int temp = map[p];
			map[p] = map[q];
			map[q] = temp;
			p++; q--;
		}
	}
	if (L < q) qsort(map, L, q);
	if (R > p) qsort(map, p, R);
}

int bsearch(int L, int R, int Q) {
	while (L <= R) {
		int mid = (L + R) / 2;
		if (n[mid] == Q) return mid;
		else if (n[mid] > Q) {
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}
	return -1;
}

int main() {
	//freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &n[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) scanf("%d", &m[i]);
	qsort(n, 0, N - 1);
	for (int i = 0; i < M; i++) {
		if (bsearch(0, N - 1, m[i]) != -1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
```

## Tree

## segment tree

### 부분합

```c
#include <stdio.h>
int N, M;
int a[100001*4], ctree[100001*4];

int init(int p, int q, int node) {
	if (p == q) return ctree[node] = a[p];
	int mid = (p + q) / 2;
	return ctree[node] = init(p, mid, node * 2) + init(mid + 1, q, node * 2 + 1);
}
int gtree(int p, int q, int node, int L, int R) {
	if (R < p || q < L  ) return 0;
	if (L <= p && q <= R) return ctree[node];
	int mid = (p + q) / 2;
	return gtree(p, mid, node * 2, L, R) + gtree(mid + 1, q, node * 2 + 1, L, R);
}
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d",&N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	int sum = init(1,N,1);
	for (int k = 1; k <= M; k++) {
		int i = 0, j = 0;
		scanf("%d %d", &i, &j);
		int out = gtree(1, N, 1, i,j);
		printf("%d\n", out);
	}
	return 0;
}
```

문제를 segment tree로 정리할 수 도 있는데... 그냥 선형으로 더해 놓고 구간에 영역을 빼면 쉽게 구했군

```c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, a, b;
vector<int> vec;
int main()
{
    cin.tie(NULL);
	cout.tie(NULL);
	iostream::sync_with_stdio(false);
 	cin >> N >> M;
	vec.resize(N);
	for (int i = 1; i <= N; ++i){
		cin >> vec[i];
		vec[i] += vec[i - 1];
	}
	while (M--){
		cin >> a >> b;
		cout << vec[b] - vec[a - 1] << '\n';
	}
	return 0;
}
```

부분합

```c
#include <stdio.h>
int N, M, K;
long long ctree[1000001 * 4], in[1000001 * 2];

long long build(int S, int E, int node) {
	if (S == E) return ctree[node] = in[S];
	int mid = (S + E) / 2;
	return ctree[node] = build(S, mid, node * 2) + build(mid + 1, E, node * 2 + 1);
}

long long sum(int S, int E, int node, int p, int q) {
	if (p > E || q < S) return 0;
	if (p <= S && q >= E) return ctree[node];
	int mid = (S + E) / 2;
	return sum(S, mid, node * 2, p, q) + sum(mid + 1, E, node * 2 + 1, p, q);
}

void rebuild(int S, int E, int node, int index, long long diff) {
	if (index < S || index > E) return;
	ctree[node] += diff;
	if (S != E) {
		int mid = (S + E) / 2;
		rebuild(S, mid, node * 2, index, diff);
		rebuild(mid + 1, E, node * 2 + 1, index, diff);
	}
}


long long a, b, c;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
	}
	build(1, N, 1);
	for (int i = 1; i <= M + K; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 2) {
			long long ans = sum(1, N, 1, b, c);
			printf("%lld\n", ans);
		}
		else if (a == 1) {
			long long diff = c - in[b];
			in[b] = c;
			rebuild(1, N, 1, b, diff);
		}
	}
	return 0;
}
```

### segment tree rebuild

- rebuild

```c
#include <stdio.h>
int N, M, K;
long long ctree[1000001 * 4], in[1000001 * 2];

long long build(int S, int E, int node) {
	if (S == E) return ctree[node] = in[S];
	int mid = (S + E) / 2;
	return ctree[node] = build(S, mid, node * 2) + build(mid + 1, E, node * 2 + 1);
}

long long sum(int S, int E, int node, int p, int q) {
	if (p > E || q < S) return 0;
	if (p <= S && q >= E) return ctree[node];
	int mid = (S + E) / 2;
	return sum(S, mid, node * 2, p, q) + sum(mid + 1, E, node * 2 + 1, p, q);
}

void rebuild(int S, int E, int node, int index, long long diff) {
	if (index < S || index > E) return;
	ctree[node] += diff;
	if (S != E) {
		int mid = (S + E) / 2;
		rebuild(S, mid, node * 2, index, diff);
		rebuild(mid + 1, E, node * 2 + 1, index, diff);
	}
}

long long a, b, c;
int main() {
	//freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
	}
	build(1, N, 1);
	for (int i = 1; i <= M + K; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 2) {
			long long ans = sum(1, N, 1, b, c);
			printf("%lld\n", ans);
		}
		else if (a == 1) {
			long long diff = c - in[b];
			in[b] = c;
			rebuild(1, N, 1, b, diff);
		}
	}
	return 0;
}
```
### segment tree 곱하기
```c
#include <stdio.h>
const int div = 1000000007;
int N, M, K;
int in[1 << 20];
long long  ctree[(1 << 20) * 2];

long long   build(int L, int R, int node) {
	int p = L, q = R, m = (L + R) / 2;
	if (p == q) return ctree[node] = in[L];
	return ctree[node] = ((build(p, m, node * 2) % div) * (build(m + 1, q, node * 2 + 1) % div)) % div;
}

long long  getsum(int L, int R, int node, int from, int to) {
	int p = L, q = R, m = (L + R) / 2;
	if (from > R || to < L) return 1;
	if (from <= L  && to >= R ) return ctree[node];
	return  (getsum(p, m, node * 2, from, to) % div) * (getsum(m + 1, q, node * 2 + 1, from, to) % div);
}

void rebuild(int L, int R, int node, int key, int value) {
	int p = L, q = R, m = (L + R) / 2;
	if (key<p || key >q) return;
	ctree[node] = ctree[node]  / in[key];
	ctree[node] = (ctree[node] * value) % div;
	if (p == q) return;
	rebuild(p, m, node * 2, key, value);
	rebuild(m + 1, q, node * 2 + 1, key, value);
}

void rebuild_b(int L,int R, int node, int value) {
	int child = node, parent = child / 2;
	ctree[child] = value % div;
	while (parent > 0) {
		ctree[parent] = (ctree[parent * 2] * ctree[parent * 2 + 1])%div;
		child = parent;
		parent = child/2;
	}
}

int a, b, c;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
	}
	build(1, N, 1);
	for (int i = 1; i <= M + K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			int p = 1, q = N, m = (p + q) / 2, node=1;
			while (p != q) {
				m = (p + q) / 2;
				if (p == q) break;
				if (b <= m) { 
					p = p; q = m; node = node * 2; 
				}
				else {
					p = m + 1; q = q; node = node * 2 + 1;
				}
			}
			rebuild_b(1, N, node, c);
			//rebuild(1,N,1,b,c);
		}else  if (a == 2) {
				printf("%lld\n", getsum(1, N, 1, b, c) % div);
		}
	}

}
```

## heap

### max heap

```c
#include<stdio.h>


int N, hcount;
int heap[100010];

void push(int n) {
	heap[++hcount] = n;
	int child = hcount;
	int parent = child / 2;
	while (child > 1 && heap[child] > heap[parent]) {
		int temp = heap[child];
		heap[child] = heap[parent];
		heap[parent] = temp;
		child = parent;
		parent = child / 2;
	}
}

int pop() {
	if (hcount == 0) return 0;
	int ret = heap[1];
	heap[1] = heap[hcount];
	hcount--;

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= hcount)  child = (heap[child] > heap[child + 1]) ? child : child + 1;
	while (child <= hcount && heap[child] > heap[parent]) {
		int temp = heap[child];
		heap[child] = heap[parent];
		heap[parent] = temp;
		parent = child;
		child = parent * 2;
		if (child + 1 <= hcount)  child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}
	return ret;
}

int a, b;
int main() {
	//freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a);
		if (a == 0) printf("%d\n", pop());
		else push(a);
	}
	return 0;
}
```

### Min heap

```c
#include<stdio.h>
int N, hcount;
int heap[100010];

void push(int n) {
	heap[++hcount] = n;
	int child = hcount;
	int parent = child / 2;
	while (child > 1 && heap[child] < heap[parent]) {
		int temp = heap[child];
		heap[child] = heap[parent];
		heap[parent] = temp;
		child = parent;
		parent = child / 2;
	}
}

int pop() {
	if (hcount == 0) return 0;
	int ret = heap[1];
	heap[1] = heap[hcount];
	hcount--;

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= hcount)  child = (heap[child] < heap[child + 1]) ? child : child + 1;
	while (child <= hcount && heap[child] < heap[parent]) {
		int temp = heap[child];
		heap[child] = heap[parent];
		heap[parent] = temp;
		parent = child;
		child = parent * 2;
		if (child + 1 <= hcount)  child = (heap[child] < heap[child + 1]) ? child : child + 1;
	}
	return ret;
}

int a, b;
int main() {
	//freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a);
		if (a == 0) printf("%d\n", pop());
		else push(a);
	}
	return 0;
}
```

### heap

```c
#include<stdio.h>

int N;
int heap[100010];
int hcount=0;

void push(int n) {
	heap[++hcount] = n;
	int child = hcount;
	int parent = child / 2;
	while (child > 1 && heap[child] > heap[parent]) {
		int temp = heap[child];
		heap[child] = heap[parent];
		heap[parent] = temp;
		child = parent;
		parent = child / 2;
	}
}

int pop() {
	if (hcount == 0) return 0;
	int ret = heap[1];
	heap[1] = heap[hcount];
	hcount--;

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= hcount)  child = (heap[child] > heap[child + 1]) ? child : child + 1;
	while ((child <= hcount) && (heap[child] > heap[parent])) {
		int temp = heap[child];
		heap[child] = heap[parent];
		heap[parent] = temp;
		parent = child;
		child = parent * 2;
		if (child + 1 <= hcount)  child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}
	return ret;
}

int a, b;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a);
		if (a == 0) printf("%d\n", pop());
		else push(a);
	}
	return 0;
}
```


### 허프만 엔코딩
```c
#include<stdio.h>
#include<malloc.h>
typedef struct node* pnode;
typedef struct node {
	char C;
	pnode  L;
	pnode R;
};
pnode createNode(char c, pnode left, pnode right) {
	pnode p = (pnode)malloc(sizeof(node));
	p->C = c;
	p->L = left;
	p->R = right;
	return p;
}

void buildTree(pnode ht, char c, char* bin) {
	int k = 0;
	pnode tree = ht;
	while (bin[k] != '\0') {
		if (bin[k] == '0') {
			if (tree->L == NULL) tree->L = createNode(c, NULL, NULL);			
			tree = tree->L;
		}
		else {
			if (tree->R == NULL) tree->R = createNode(c, NULL, NULL);						
			tree = tree->R;
		}
		k++;
	}	 
}

char decode(pnode ht, char* code, int *idx) {
	pnode  tree= ht;	
	int k = *idx;
	while (tree->L != NULL || tree->R != NULL) {
		if (*(code + k) == '0') 
			tree = tree->L;
		else 
			tree = tree->R;
		k++;
	}
	*idx = k;
	return tree->C;
}

int N;
pnode htree;
int main() {
	char C;
	char str[10];
	char bin[20];
	htree = (pnode)malloc(sizeof(node));
	htree->C = '\0'; htree->L = NULL; htree->R = NULL;;

	scanf("%d", &N); {
		for (int i = 0; i < N; i++) {
			scanf("%s %s", &str, &bin);		
			C = str[0];
			buildTree(htree, C, bin);			
		}
	}
	char code[1000];
	char c;
	scanf("%s", &code);
	int k = 0;
	while (code[k] != '\0') {
		c = decode(htree, code, &k);
		printf("%c", c);		
	}
}
```



```c
#include <stdio.h>
int Y = 2009, M, D;
int days;
int month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char Days[7][15] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d %d", &D, &M);
	for (int y = 1; y < Y; y++) {
		if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)) 
			days += 366;
		else 
			days += 365;
	}
	
	if ((Y % 4 == 0) && (Y % 100 != 0) || (Y % 400 == 0)) 
		month[1] = 29;
	for (int i = 0; i < M - 1; i++) days += month[i];
	
	days += D;
	printf("%s\n", Days[days % 7]);
		
	return 0;
}

```


## 수열

### 수열

```c
#include <stdio.h>
int N,ans;
int a[5];
void call(int n, int step) {
    a[step]=n;
    if (step ==4){
        ans++;
        for (int i=1; i<=4; i++) printf("[%d]", a[i]);
        printf("\n");
        return;
    }
    for (int i=n-1; i>=1; i--){
        call(i, step+1);
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d",&N);
    call(N+1,0);
    printf("%d", ans);
}
```



## 출력시간 단축

#### 문장변환 출력

#### 1. case:  매핑 테이블 이용
* 380ms 512B

```c
#include <stdio.h>
int AB[26];
int BA[26];
int T,a,b;
char s1[1<<20];
void build(int a,int b){
    int temp=0;
    for (int i=0;i<26; i++){        
        temp = (a*i+b)%26;
        AB[i] =temp;
        BA[temp] =i;
    }
}
int main()
{    
    scanf("%d", &T) ;
    for (int i = T; i; i--){
        scanf("%d %d",&a,&b);
        scanf("%s",s1);
        build(a,b);
        for (int j=0;s1[j]; j++){
            char c=s1[j]-'A';
            printf("%c", AB[c]+'A');
        }
        printf("\n");
    }    
}
```
#### 2. case: puts 함수 이용
* 144ms 464B
```c
#include <stdio.h>
int AB[26];
int T,a,b;
char s1[1<<20];
void build(int a,int b){
    int temp=0;
    for (int i=0;i<26; i++){        
        temp = (a*i+b)%26;
        AB[i] =temp;        
    }
}
int main()
{   
    scanf("%d", &T) ;
    for (int i = T; i; i--){
        scanf("%d %d",&a,&b);
        scanf("%s",s1);
        build(a,b);
        for (int j=0;s1[j]; j++){            
            s1[j]= AB[s1[j]-'A']+'A';
        }
        puts(s1);
    }    
}
```

#### 3. case: no map table
* 132ms 307B
```c
#include <stdio.h>
int T,a,b;
char s1[1<<20];
int main()
{       
    scanf("%d", &T) ;
    for (int i = T; i; i--){
        scanf("%d %d",&a,&b);
        scanf("%s",s1);    
        for (int j=0;s1[j]; j++){            
            s1[j]= (a*(s1[j]-'A')+b)%26 + 'A';
        }
        puts(s1);
    }    
}
```


### big number

```c
#include <stdio.h>
char a[1020], b[1020], c[1020];
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%s", a);
    int len=0;
    for (int i=0; a[i]; i++) len++;
    b[0]='0';
    int i=1; 
    for (int j=0; a[j];j++){b[i++]=a[j]; }
    for (int j=0; j<4; j++) b[i++]='0'; // <<4

    
    for (int i=len+5; i>=0; i--){
        if ((i-5)>=0){
            c[i] = ((a[i-5]-'0')+(b[i]-'0')) + '0';
        }else{
            c[i] = b[i];
        }
    }
    c[len+5]='\0';

    for (int i=len+5; i>=1; i--){
        if (c[i] =='2') {
            c[i] ='0';
            c[i-1] = (c[i-1]-'0' +1)+'0';
        } 
        if (c[i] =='3') {
            c[i] ='1';
            c[i-1] = (c[i-1]-'0' +1)+'0';
        } 
    }    
    int start =0;
    for (int i=0;c[i]; i++){
        if (c[i]=='1') start=1;
        if (start)  printf("%c",c[i]);    
    }    
}
```

```c
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char num[1001];
    char ret[1011];
    for( int i = 0 ; i < 10 ; ++i ) ret[i] = '0';
    scanf("%s", num);
    memcpy(ret+4, num, sizeof(num));
    int idx = (int)strlen(num)-1;
    int carry = 0;
    for( ; idx >= 0 ; --idx){
        int a = ret[idx]-'0', b = num[idx]-'0';
        ret[idx] = (a+b+carry)%2+'0';
        carry = a+b+carry > 1;
    }
    if( carry ) printf("1");
    printf("%s", ret);
    return 0;
}
```

#### 이진수 변환
```c
#include <stdio.h>
int main() {
	int i = 0, d[50];
	long long n;
	scanf("%lld", &n);
	while (n) {
		if (n % 2) d[i++] = 1;
		else d[i++] = 0;
		n /= 2;
	}
	while (i--)
		printf("%d", d[i]);
	return 0;
}
```

#### 이진수 곱셈
```c
#include <stdio.h>
char s1[1<<5], s2[1<<5];
long long a,t;
int ans[64];
int main(){    
    freopen("data.txt","r",stdin);
    scanf("%s %s", s1,s2);
    for(int i=0; s1[i]; i++){
        a=a<<1;
        a+=(s1[i]-'0');
    }
    int len=0;
    for(int i=0; s2[i]; i++) len++;
    for ( int i=len-1, j=0; i>=0; i--, j++){
        if (s2[i]=='1') {
            t+=a<<j;
        }
    }
    for (int i=63; i>=0; i--){
        if (t&1==1) ans[i]=1;
        else ans[i] =0;
        t=t>>1;
    }
    int start=0;
    for (int i=0; i<64; i++){
        if (ans[i]==1) start=1;
        if (start) printf("%d", ans[i]);
    }
}
```

#### 큰수 나누기
https://www.acmicpc.net/problem/14928
```c
#include<stdio.h>
char S[1000010];
int ans;
int main() {	
	fgets(S, 1000010, stdin);
	for (int i=0; S[i]!='\n'; i++) ans = ((ans*10) +S[i] - '0') % 20000303;
	printf("%d", ans);
}
```

#### scanf에서 '\n' 문자 까지 읽기 
```c
#include<stdio.h>

char st[111];
int main(){
	int n, t, i;
	for(scanf("%d\n",&n);n--;){
		gets(st);
		for(i=t=0;st[i];i++){
			if('a'<=st[i]&&st[i]<='z')t|=1<<(st[i]-'a');
			if('A'<=st[i]&&st[i]<='Z')t|=1<<(st[i]-'A');
		}
		if(t==(1<<26)-1)puts("pangram");
		else{
			printf("missing ");
			for(i=0;i<26;i++)if((t&(1<<i))==0)putchar('a'+i);
			puts("");
		}
	}
	return 0;
}
```

### struct 선언 방법
#### typedef 
* struct typedef : 구조체의 이름 앞에는 관례상 `_`를 접두사로 사용
* struct pointer를 사용할 때 표현 단순화 
```
typedef struct _Person {
	char name[20];
	int age;
	char address[100];
} Person;

typedef struct _Person* pPerson;
```
typedef struct _DP* pdp;
typedef struct _DP {
	int v, k;
} DP;
```
