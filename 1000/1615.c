#include <stdio.h>
#include <malloc.h>

int comp(char * str1, char *str2) {
	int i = 0;
	int j = 0;
	while (*(str1 + i++) == *(str2 + j++)) {
		if (*(str1 + i) == '\0' &&*(str2 + j) == '\0') return 1;
	}
	return 0;
}

int isEND(char *str) {
	if (*(str) == 'E' && *(str + 1) == 'N' && *(str + 2) == 'D') return 1;
	else return 0;
}


int add_dic(char * str, char **dic,int* cnt, int *N) {
	if (*N > 0) {
		for (int i = 0; i < *N; i++) {
			if (comp(str, *(dic + i)) ) { 
				*(cnt + i) += 1;
			}
			else
			{
				int j = 0;
				*N += 1;
				while (*(str + j) != '\0') {
					*(*(dic + *N) + j) = *(str + j);
					j++;
				}
				*(*(dic + *N) + j) = '\0';
			}
		}
		return 1;
	}
	else
	{
		int j = 0;
		while (*(str + j) != '\0') {
			*(*(dic + *N) + j) = *(str + j);
			j++;
		}
		*(*(dic + *N) + j) = '\0';
		*N += 1;

	    return 0;
	}
}

void print_result(char **dic, int * cnt, int *N) {
	for (int i = 0; i < *N; i++) {
		printf("%s : %d\n", *(dic + i), *(cnt + i));
	}
}

int main() {
	int i, j, k;
	char line[256] = { '\0', };
	char str[256] = { '\0', };
	char **dic = (char**)malloc(sizeof(char*));
	for (int i = 0; i < 100; i++)
		*(dic + i) = (char*)malloc(sizeof(char) * 100);
	int cnt[200] = { 0, };
	int N=0;
	freopen("data.txt", "r", stdin);
	while ( fgets(line, sizeof(line), stdin) != NULL) {
		i = 0;
		j = 0;
		while (  *(line + i) != '\n' )  {
			printf("%c", *(line + i));
			if (*(line + i) != ' ') {
				str[j++] = *(line + i);
			}
			else {
				str[j++] ='\0';
				j = 0;
				if (isEND(str)) {
					return 1;
				}
				//string check 함수 만들어서 누적 하는 부분 생성한다. 
				add_dic(str, dic, cnt, &N);
			}
			i++;
		}
		//printf("%d \n", comp(line, line));
		print_result(dic, cnt, &N);
		for (int i = 0; i < N; i++) *(cnt + i) = 0;
		N = 0;
	}
	
}
