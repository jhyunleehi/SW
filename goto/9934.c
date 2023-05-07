#include <stdio.h>
int N;
double size=1;
int main()
{
    freopen("data.txt", "r", stdin);
    for (int i=0;i<N; i++){
        size *=2;
    }
    size--;
    
}
