/**************************************************************
    Problem: 1516
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
/**************************************************************
Problem: 1516
User: jhyunlee
Language: C
Result: Runtime Error
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int strCmp(char *s, char *t) {
    while (*s&&*s == *t) { s++; t++; }
    return *s - *t;
}
void strCpy(char *dest, char *src) {
    while (*src&&*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
}
 
int main() {
    char str[500];
    char word[101][201];
    char mapc[101][201];
    int  mapi[101] = { 0, };
    int  max = 0;
    int  wcnt;
    int i, j;
    char END[] = "END";
    //freopen("data.txt", "r", stdin);
 
    while (1) {
        //mapi[201] = { 0, };
        i = 0;
        //while (1) {
        //  scanf("%c", &str[i]);
        //  if (str[i] == '\n') break;
        //  i++;
        //}
        //str[i] = '\0';
 
        fgets(str, 501, stdin);
 
        int strlength = 0;
        i = 0;
        while ((str[i] != '\0') && (str[i] != '\n') && (str[i] != '\r')) {
            i++;
            strlength++;
        }
        if (strlength == 0) continue;
 
 
        //printf("[%s] \n", str);
 
        i = 0;
        /*
        while (str[i] != '\n') {
        if (str[i] == '\n') str[i--] = '\0';
        if (str[i] == '\r') str[i--] = '\0';
        i++;
        }*/
        i = j = 0;
        wcnt = 0;
        while (str[i] != '\0' && str[i] == ' ') i++;
        while (str[i] != '\0') {
            if ((str[i] != ' ') && (str[i] != '\n') && (str[i] != '\r'))
                word[wcnt][j++] = str[i];
            else if (str[i + 1] != ' ') {
                word[wcnt++][j] = '\0';
                j = 0;
            }
            i++;
        }
        word[wcnt][j] = '\0';
 
        if (0 == strCmp(END, word[0])) return 1;
 
        int last = 1;
        int key = last - 1;
        for (i = 0; i <= wcnt; i++) {
            //printf("%s\n", word[i]);
            /*if (mapk == 0) {
            strCpy(mapc[mapk], word[i]);
            mapi[mapk]++;
            mapk++;
            continue;
            }*/
            key = last - 1;
            int meet = 0;
            while (key >= 0) {
                int rtn = strCmp(mapc[key], word[i]);
                if (rtn == 0) {
                    mapi[key]++;
                    meet = 1;
                    break;
                }
                key--;
            }
            key = last - 1;
            if (0 == meet) {
                while (key >= 0) {
                    int rtn = strCmp(mapc[key], word[i]);
                    if (key == 0) {
                        strCpy(mapc[key + 1], word[i]);
                        mapi[key + 1] = 1;
                        last++;
                        break;
                    }
                    if (rtn < 0) {
                        strCpy(mapc[key + 1], word[i]);
                        mapi[key + 1] = 1;
                        last++;
                        break;
                    }
                    else if (rtn > 0) {
                        strCpy(mapc[key + 1], mapc[key]);
                        mapi[key + 1] = mapi[key];
                        key--;
                    }
                }
            }
        }
 
        for (i = 1; i < last; i++) {
            printf("%s : %d\n", mapc[i], mapi[i]);
        }
        for (i = 0; i < last; i++) {
            mapc[i][0] = '\0';
            mapi[i] = 0;
        }
    }
    return 1;
}
