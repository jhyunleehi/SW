#include <stdio.h>
int N;
char str[50];
char A[27], B[27];
int a[27], b[27];
int length;
int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (; N > 0; N--)
    {
        scanf("%s", str);
        length=0;
        while (str[length] != '\0') length++;
        if (length%2==1){
            for(int i=length, j=0; j<length;j++,i++){
                str[i]=str[j];
            }
            str[length*2]='\0';
            length=length*2;
        }
        for (int i = 0; i < length; i+=2)
        {            
            A[i/2] = str[i];
            B[i/2] = str[i+1];            
        }
        A[length/2] = '\0';
        B[length/2] = '\0';       
        printf("%s\n", A);
        printf("%s\n", B);
    }
}