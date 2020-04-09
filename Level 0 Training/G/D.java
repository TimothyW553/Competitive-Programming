import java.util.*;

public class D {

    public static long max_number(long[] a, long max, int i) {
        if(i == 0) {
            return Math.max(a[i], max);
        } else {
            return max_number(a, Math.max(max, a[i]), i-1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        long max_val = max_number(a, -99999L, n-1);
        System.out.println(max_val);
    }
}
