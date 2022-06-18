#include<stdio.h>
int N;
char str[51];
char data[1000][51];
int  cnt[1000];
int num;

char *strcpy(char *s, const char *t){
    char *os;
    os=s;
    while((*s++=*t++)!=0);
    return os;
}

int strcmp(const char *p, const char *q){
    while (*p && *p==*q) p++, q++;
    return *p - *q;
}

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d", &N);
    int find=0;
    while(N--){
        scanf("%s",str);
        find =0;
        for (int i=0; i<num; i++){
            if (strcmp(data[i], str)==0){
                find =1;
                cnt[i]++;
                break;                
            }
        }
        if (find==0) {
            strcpy(data[num], str);
            cnt[num]++;
            num++;
        }        
    }  
    int max=-1;
    int ans=0;
    for (int i=0; i<num; i++){
        if (max<cnt[i]) {
            ans=i;
            max = cnt[i];
        }
    }   

    char temp[51];
    strcpy(temp, data[ans]);
    for (int i=0; i<num; i++){
        if (cnt[i]==max) {
            if (strcmp(data[i], temp) <0 ){
                strcpy(temp, data[i]);
            }                        
        }
    }
    printf("%s\n", temp);
}