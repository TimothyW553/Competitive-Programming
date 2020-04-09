import java.util.*;

public class C {

    public static long factorial(int n) {
        long prod = 1;
        for(int i = 1; i <= n; i++) {
            prod *= i;
        }
        return prod;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long ans = factorial(n);
        System.out.println(ans);
    }
}
