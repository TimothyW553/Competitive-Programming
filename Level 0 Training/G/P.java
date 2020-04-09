import java.util.*;

public class P {

    public static long log2N(long n) {
        if(n < 2) {
            return 0;
        }
        return 1 + log2N(n / 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long ans = log2N(n);
        System.out.println(ans);
    }
}
