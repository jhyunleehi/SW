#include <stdio.h>

int N;
char str[1 << 5];
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        fgets(str, 1 << 5, stdin);
        int bad = 0, good = 0;
        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] == 'b' || str[j] == 'B') bad++;
            if (str[j] == 'g' || str[j] == 'G') good++;
        }        
        for (int i = 0; str[i] != '\n'; i++) printf("%c", str[i]);
        if (good > bad) {
            printf(" is GOOD\n");
        }else if (good < bad) {        
            printf(" is A BADDY\n");
        }
        else {
            printf(" is NEUTRAL\n");
        }
    }    
}
