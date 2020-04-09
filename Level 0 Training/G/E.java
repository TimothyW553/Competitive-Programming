import java.util.*;

public class E {

    public static long combination(long n, long r) {
        if(r == 0 || r == n) {
            return 1;
        } else {
            return (n * combination(n-1, r-1)) / r;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long r = sc.nextLong();
        long ans = 0;
        if(r <= n) {
            ans = combination(n, r);
        }
        System.out.println(ans);
    }
}
