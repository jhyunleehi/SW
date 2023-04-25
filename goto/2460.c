/**************************************************************
    Problem: 2460
    User: jhyunlee
    Language: C++
    Result: Success
    Time:1 ms
    Memory:1092 kb
****************************************************************/
 
 
#include<stdio.h>
#include<malloc.h>
 
int main() {
    int N;
    int S[3][4] = { 0, }; 
    int IS[3] = { 0, };
    //freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &IS[0], &IS[1], &IS[2]);
        //printf("%d %d %d \n", IS[0], IS[1], IS[2]);
        for (int j = 0; j < 3; j++) {
            //printf("%d \n", IS[j]);
            switch (IS[j]) {
            case 3:
                S[j][2] ++;
                S[j][3] += 3;
                break;
            case 2:
                S[j][1] ++;
                S[j][3] += 2;
                break;
            case 1:
                S[j][0] ++;
                S[j][3] += 1;
                break;
            }
        }
 
    //  printf("%d %d %d \n", S[0][3], S[1][3], S[2][3]);
    }
    /*
    for (int i = 0; i < 3; i++) {
        printf("%d %d %d %d \n", S[i][0], S[i][1], S[i][2], S[i][3]);
    }
    */
    int max = 0, cnt = 0, top = -1;
    for (int i = 0; i < 3; i++) { 
        if (max < S[i][3]) {
            max = S[i][3];
            top = i;
        }
    }
    for (int i = 0; i < 3; i++) if (max == S[i][3]) cnt++;
    if(cnt==1){ 
        printf("%d %d\n", top+1, max);
        return 1;
    } else if ((cnt == 2)|| (cnt == 3)) {
        int max3cnt = 0;
        cnt = 0;
        top = -1;
        for (int i = 0; i < 3; i++) {
            if (max3cnt < S[i][2]) {
                max3cnt = S[i][2];
                top = i;
            }
        }
        for (int i = 0; i < 3; i++) if (max3cnt == S[i][2]) cnt++;
        if (cnt == 1) {
            printf("%d %d\n", top+1, max);
            return 1;
        }
        else if ((cnt = 3) || (cnt == 2)) {
            int max2cnt = 0;
            cnt = 0;
            top = -1;
            for (int i = 0; i < 3; i++) {
                if (max2cnt < S[i][2]) {
                    max2cnt = S[i][1];
                    top = i;
                }
                }
            for (int i = 0; i < 3; i++) if (max2cnt == S[i][1]) cnt++;
            if (cnt == 1) {
                    printf("%d %d\n", top+1, max);
                    return 1;
            }else {
                    printf("%d %d\n", 0, max);
                    return 0;
            }
 
        }
    }
    return 1;
}
