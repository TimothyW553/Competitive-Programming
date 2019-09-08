import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String temp = sc.nextLine();
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            String ans = temp;
            String str = sc.next();
            ans = ans.replaceAll(">", str);
            System.out.println(ans);
        }
    }
}
