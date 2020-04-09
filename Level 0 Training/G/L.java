import java.util.*;

public class L {

    public static void printEven(long[] a, int i) {
        if(i == 0) {
            System.out.println(a[0]);
        } else {
            if(i % 2 == 0) {
                System.out.print(a[i] + " ");
            }
            printEven(a, i-1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        printEven(a, n-1);
    }
}
