import java.util.*;

public class A {

    public static void one_to_n(int n, int cur) {
        if(cur == n) {
            System.out.println(n);
        } else {
            System.out.println(cur);
            one_to_n(n, cur+1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        one_to_n(n, 1);
    }
}
