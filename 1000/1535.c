#include<stdio.h>
#include<malloc.h>


int strComp(char *s, char *t) {
	while (*s&&*s == *t) { s++; t++; }
	return *s - *t;
}
void strCopy(char *dest, char *src) {
	while (*src&&*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
}


int main() {

	char line[51];
	char word[500][51];
	char wlist[500][51];
	int cnt = 0;
	int wcnt = 0;
	char END[] = "END";
	int i, j;
	freopen("data.txt", "r", stdin);	
	
	while (1) {
		i = 0;
		while (1) {
			scanf("%c", &line[i]);
			if (line[i] == '\n') break;
			i++;
		}
		line[i] = '\0';
		//printf("[%s] \n", str);
		if (0 == strComp(END, line)) return 1;

		i = j = 0;
		wcnt = 0;
		while (line[i] != '\0' && line[i] == ' ') i++;
		while (line[i] != '\0') {
			if ((line[i] != ' ') && (line[i] != '\n') && (line[i] != '\r'))
				word[wcnt][j++] = line[i];
			else if ((line[i] == ' ') || (line[i] == '\0')) {
				word[wcnt++][j] = '\0';
				j = 0;
			}
			i++;
		}
		word[wcnt][j] = '\0';
		
		for (int i = 0; i <= wcnt; i++) printf("%s ", word[i]);			

		bool exist = false;
		int last = 0;		
		for (i = 0; i <= wcnt; i++) {
			for (int k = 0; k <= last; k++) {
				if(0 ==strComp(wlist[k], word[i])) exist = true;
				else exist = false;
				break;
			}

			if (! exist) {
				strComp(wlist[last], word[i]);
				last++;
			}
			meet = false;
			for (int i = 0; i < last; i++) printf("%s ", wlist[i]);
			printf("\n");
		}
	}
	return 1;
}
