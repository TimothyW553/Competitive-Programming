import java.util.*;

public class N {

    public static String digits(int i, int n, String res, String s) {
        if(i == n) {
            return res;
        }
        return digits(i+1, n, res+s.charAt(i)+" ", s);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            String s = sc.next();
            String ans = digits(0, s.length(), "", s);
            System.out.println(ans.substring(0, ans.length()-1));
        }
    }
}
