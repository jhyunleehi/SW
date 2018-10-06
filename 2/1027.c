/**************************************************************
    Problem: 1027
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
  
/*
1. 1,2,3으으로 구성된 N자리 숫자열에서 인접하게 중복되지 않은 가장 작은 숫자열을 선택
2. 1에서 N까지 증가하는 각 자리수에서 선택할 수 있는(1~3 중에서 하나) 가장 작은 수를 선택한다.
3. 선택해야 하는 위치 P에서 P-1, P-3{P-3, P-2, P-1,P}를 비교하여 P자리에서 가장 작은 수를 선택한다.
4. {0...P}일때 P에서 P-1, P-3, P-5, P-7.. 까지에서 (P+P-3)/2 기준으로 각각 비교하여 선택가능한 최소의 수를 선택한다.  
5 최초 자리수는 1을 선택한다. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
 
int N;
char *L;
char str1[81];
char str2[81];
 
bool strcmp(char *src, char *dst, int N) {
    int i = 0;
    while (*(src + i) == *(dst + i)) {
        i++;
        if (i == N) return true;
    }
    return false;
}
 
bool strcpy(char *src, char* dst, int F, int N) {  //F자리에서 N개 복사
    int i = 0;
    while (i < N) {
        *(dst + i++) = *(src + F++);        
    }
    *(dst + i) = '\0';
    return true;
}
 
bool choose(char *L, int P, int N) {
    //printf("P:%d L:%d (%s)\n", P, N, L);
    if (P >= N) {
        printf("%s\n", L);
        return true;
    }
 
    int M = P / 2;
    int K = 1;
    for (int i = P; i > M; i--) {
        strcpy(L, str1, (P- K)+1, K);
        strcpy(L, str2, (P - K*2)+1, K);
        //printf("[%s][%s] \n", str1, str2);
        if (strcmp(str1, str2, K)) return false;
        K++;
    }
    for (int i = 0; i <= 2; i++) {
        *(L + P + 1) = i + '1';
        *(L + P + 2) = '\0';
        if (choose(L, P + 1, N))
            return true;
    }
}
 
 
int main() {
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    L = (char *)malloc(sizeof(char)*N + 1);
 
    *(L) = '1';
    *(L+1) = '\0';
    choose(L, 0, N-1);
    return 0;
}
