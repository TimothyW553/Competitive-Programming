import java.util.*;
import java.io.*;

public class CCC_2018_J3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        System.out.println(0 + " " + a + " " + (a+ b) + " " + (a+b+c) + " " + (a+b+c+d ));
        System.out.println(a + " " + 0 + " " + (b) + " " + (b+c) + " " + (b+c+d ));
        System.out.println((a+b) + " " + b + " " + (0) + " " + (c) + " " + (c+d));
        System.out.println((a+b+c) + " " + (b+c) + " " + (c) + " " + (0) + " " + (d));
        System.out.println((a+b+c+d) + " " + (b+c+d) + " " + (c+d) + " " + (d) + " " + (0)); 
    }
}
