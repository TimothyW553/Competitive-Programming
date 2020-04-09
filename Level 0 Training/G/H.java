import java.util.*;

public class H {

    public static boolean isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    public static int countVowels(String s, int i, int n) {
        if(i == 0) {
            if(isVowel(s.charAt(i))) {
                return n+1;
            } else {
                return n;
            }
        }
        if(isVowel(s.charAt(i))) {
            return countVowels(s, i-1, n+1);
        } else {
            return countVowels(s, i-1, n);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        s = s.toLowerCase();
        int ans = countVowels(s, s.length()-1, 0);
        System.out.println(ans);
    }
}
