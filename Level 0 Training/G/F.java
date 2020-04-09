import java.util.*;

public class F {

    public static long GCD(long x, long y) {
        if(y == 0) {
            return Math.abs(x);
        }
        return GCD(y, x % y);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        long y = sc.nextLong();
        long ans = (y > x) ? GCD(x, y) : GCD(y, x);
        System.out.println(ans);
    }
}