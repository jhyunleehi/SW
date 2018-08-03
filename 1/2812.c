/**************************************************************
    Problem: 2812
    User: jhyunlee
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1092 kb
****************************************************************/
 
 
#include <stdio.h>
#include <malloc.h>
 
void num_sum(char  * str) {     
    int sum = 0;
    char nstr[30];  
    int i = 0;
    while (*str != '\0') {
        sum += *str - '0';
        *str++;     
    }
    sprintf(nstr,"%d", sum);    
    printf("%d\n", sum);
 
    if (sum >= 10) {
        num_sum(nstr);
    }
}
int main() {
    char str[30];
    //freopen("data.txt", "r", stdin);
    scanf("%s", str);   
    num_sum(str);
    return 1;
}
