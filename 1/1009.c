/**************************************************************
    Problem: 1009
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    //freopen("data.txt", "r", stdin);
    char *nstr = (char*)malloc(sizeof(char)*(10+1));
    char *tmp;
    scanf("%s", nstr);
    while (*nstr != '0') {
        int size = 0;
        tmp = nstr;
        while (*nstr++ != NULL) size++;
        char ch;
        int sum = 0;
        *nstr--;
        *nstr--;
        size--;
        int hzero = 1;
        while (size-- >= 0) {
            ch = *nstr--;
            if ((ch == '0') && (hzero==1)) {}
            else {
                printf("%c", ch);
                hzero = 0;
            }
            sum = sum + ch - 48;            
        }
        printf(" %d\n",sum);
        scanf("%s", nstr);
    }
    return 1;
}
