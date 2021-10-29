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

