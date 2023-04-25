#include <stdio.h>
int T, len,cnt;
char instr[1 << 14];
int getsquare(int in) {
    int i = 1;
    while (i * i < in) i++;
    return i;
}
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d\n", &T);
    while (T--) {
        scanf("%s", instr);
        for (len = 0; *(instr + len) != '\0'; len++);
        cnt = getsquare(len);
        printf("%d %d\n", len,cnt);
        for (int x = cnt-1; x >=0; x--) {
            for (int y = 0; y <cnt; y++) {
                printf("%c", *(instr+((y * cnt) + x))) ;
            }
        }
        printf("\n");
    }

}