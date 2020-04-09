import java.util.*;

public class G {

    public static String toBinary(String ans, int n) {
        if(n == 0) {
            return ans;
        }
        if(n == 1) {
            return "1"+ans;
        } else {
            String add = Integer.toString(n % 2);
            n /= 2;
            return toBinary(add+ans, n);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        while(tt-- > 0) {
            int n = sc.nextInt();
            String ans = toBinary("", n);
            System.out.println(ans);
        }
    }
}
