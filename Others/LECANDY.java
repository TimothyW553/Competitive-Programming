import java.util.*;
import java.io.*;

public class LECANDY {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int c = sc.nextInt();
            int sum = 0;
            int[] arr = new int[n];
            for(int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            for(int x : arr) {
                sum += x;
            }
            if(sum <= c) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
