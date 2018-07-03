/**************************************************************
    Problem: 1740
    User: jhyunlee
    Language: Java
    Result: Success
    Time:147 ms
    Memory:8752 kb
****************************************************************/
 
 
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
 
 
public class Main{
    static int N, M;
    static ArrayList<Integer>D;
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        //System.setIn(new FileInputStream("J1740"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        D = new ArrayList<>();
        D.add(2);
        for (int i = 2; i <=M; i++) {
            for (int j = 0; j <= D.size(); j++) {
                //System.out.println(i+" "+j+" "+ D.get(j));
                if ((i%D.get(j))==0) break;
                if (D.size()==(j+1)) D.add(i);
            }           
        }
        //D.remove(0);
        //System.out.println(D.toString());
        int ans=0; int fprime=0;
        for (Integer i : D) 
            if (i>=N) { 
                ans +=i; 
                if (fprime ==0) fprime=i; 
            }   
        if (ans==0)System.out.println("-1");
        else {
            System.out.println(ans);
            System.out.println(fprime);
        }
    }
 
}
