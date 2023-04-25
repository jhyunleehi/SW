#include<stdio.h>
int M;
int N, T[7];
int S[1000+1];
void qsort(int L, int R){
    int p=L,q=R,v=S[(L+R)/2];
    while (p<q){
        while (S[p]>v) p++;
        while (S[q]<v) q--;
        if (p<=q){
            int temp=S[p];
            S[p]=S[q]; S[q]=temp;
            p++; q--;
        }
    }
    if (q>L) qsort (L,q);
    if (p<R) qsort (p,R);
}

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d", &M);
    for (int i=0;i<M; i++){
        for (int j=1; j<=6; j++) T[j]=0;
        
        for (int k=0; k<4; k++){
            scanf("%d", &N);
            T[N]++;
        }
        
        //1.count 4
        for (int p=1; p<=6; p++){            
            if (T[p]==4){
                S[i]=50000+p*5000;
                break;
            }
        }
        
        //2. count3
        if (S[i]==0){
            for (int p=1; p<=6; p++){            
                if (T[p]==3){            
                    S[i]=10000+p*1000;
                    break;         
                }
            }
        }

        //2. count 2,2
        if (S[i]==0){
            for (int p=1; p<6; p++){
                for ( int q=p+1; q<=6; q++){                
                    if ((T[p]==2) && (T[q]==2)){
                        S[i]=2000+(p*500)+(q*500);
                        break;
                    }
                }
            }    
        }    
        
        //3.  count 2
        if (S[i]==0){
            for ( int p=1; p<=6; p++){
                if (T[p]==2){
                    S[i]=1000+p*100;
                    break;
                }
            }
        }

        //4.  count 1
        if (S[i]==0){
            for (int p=6; p>=1; p--){
                if (T[p]==1){
                    S[i]=p*100;
                    break;
                }
            }
        }
    }

    qsort(0,M-1);
    printf("%d", S[0]);
}