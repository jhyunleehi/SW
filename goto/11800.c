#include <stdio.h>
char s1[7][10] = {"", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
char s2[7][10] = {"", "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};
int N, a, b;

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N) ;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: ", i);
        if ((a==5&&b==6)||(a==6&&b==5)) {
            printf("Sheesh Beesh\n");
            continue;
        }
        if (a>b) {
            printf("%s %s\n",s1[a],s1[b]);
        }else if (b>a){
            printf("%s %s\n", s1[b],s1[a]);
        }else {
            printf("%s\n", s2[a]);
        }
    }    
}
