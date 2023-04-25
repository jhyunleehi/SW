#include <stdio.h>
char s1[21], s2[21];
int n;
int main() {
	freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	while (n--) {
		scanf("%s %s", s1, s2);
		int i = 0;
		printf("Distances: ");
		while (s1[i] != '\0') {
			if (s2[i] >= s1[i]) printf("%d ", s2[i] - s1[i]);
			else printf("%d ", (s2[i] + 26) - s1[i]);
			i++;
		}
		printf("\n");
	}	
	return 0;
}