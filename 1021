import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
    static int N, M;
    static int map[][];
    static int part[];
    static int check[];
 
    public static void main(String[] args) throws IOException {
        long startTime = System.currentTimeMillis();
        //System.setIn(new FileInputStream("input1021.txt"));
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); // N N(3≤N≤100)
        M = sc.nextInt(); // M(3≤M≤100)
        map = new int[3][M+1];
        part = new int[M];
        check = new int[M+1];
        for (int i = 1; i <= M; i++) {
            map[0][i] = sc.nextInt(); // parent
            map[1][i] = sc.nextInt(); // child
            map[2][i] = sc.nextInt(); // count
        }
        for (int i = 1; i <= M; i++) {       
            check[map[0][i]] = map[0][i]; // 중간 부붚 번호가 있는지 확인
            //part[i] =1;
        }
        //System.out.println(Arrays.toString(check));
        //for (int i=7; i>1; i--)
        calcpart(N,1,0);
        for (int i = 1; i < M; i++) 
            if (part[i] != 0 ) System.out.printf("%d %d\n", i, part[i]);
        //System.out.println(Arrays.toString(part));
    }
 
    public static void calcpart(int pNum, int count, int row) {     
        //System.out.printf("call-- pNum [%d] count [%d] nNum [%d]", pNum, count, row);
        //System.out.println(Arrays.toString(part));
        if (check[pNum] == 0){
            //part[map[1][mNum]] *=map[2][mNum];
            part[map[1][row]] +=  count ;
        }       
        //System.out.println(Arrays.toString(part));
        for (int i = 1; i <= M; i++) {
            if (map[0][i] == pNum) {        
                //System.out.printf("call-->> [%d]  [%d]", map[0][i], map[1][i]);
                calcpart(map[1][i],map[2][i]*count,i);//*map[2][i];
            }
        }
         
         
    }
}
