import java.util.*;

public class B {

    public static void n_to_one(int n, int cur) {
        if(cur == 1) {
            System.out.print(cur);
        } else {
            System.out.print(cur + " ");
            n_to_one(n, cur-1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        n_to_one(n, n);
    }
}
