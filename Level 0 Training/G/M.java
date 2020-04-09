import java.util.*;

public class M {

    public static long sum(long[] a, int i, long sum) {
        if(i == 0) {
            return (sum + a[i]);
        } else {
            return sum(a, i-1, sum+a[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        long ans = sum(a, n-1, 0);
        System.out.println(ans);
    }
}
