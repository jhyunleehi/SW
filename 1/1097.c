/**************************************************************
    Problem: 1097
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
void getNum(int NN, int B, char str[]) {
    int i = 0;
    char temp[25];
    while (NN != 0) {
        int M = NN % B;
        NN = NN / B;
        if (M >= 10) 
            temp[i] = (M - 10) + 'A';
        else
            temp[i] = M + '0';
        i++;
    }
    int k = --i;
    //str[i] = '\0';
    while (i >= 0) {
        str[k - i] = temp[i];
        i--;
    }
    str[++k] = '\0';
}
 
 
bool chkNum(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    len--;
    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i]) return false;
    }
    return true;
}
 
int main() {
    int B;
    char str1[25];
    char str2[25];
    //freopen("data.txt", "r", stdin);
    scanf("%d", &B);
 
    for (int N = 1; N < 300; N++) {
        int NN = N * N;
        getNum(NN, B, str1);
        //printf("%s\n", str);
        bool rtn= chkNum(str1);
        if (rtn == true) {
            getNum(N, B, str2);
            printf("%s %s\n", str2, str1);
        }
    }
    return 1;
}
