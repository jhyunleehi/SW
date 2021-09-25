# Test

## Code

####  fread(), getbyte(), getInt(), dfs()

* 1<<20 512KB 단위로 읽어오는 것
* 읽어온 데이터 데이터 버퍼에서 원하는 만큼 char 단위로 읽어 와서 integer 변환
* dfs 구현

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



#### 에라토스테세스의 체

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



##  데이터 구조

### heap 데이터

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





### strcmp strcpy

#### strcmp

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

