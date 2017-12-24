import java.io.*;
import java.util.*;

public class CCC_2006_J1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int count = 0;
        if(a == 1) count = 461;
        if(a == 2) count = 431;
        if(a == 3) count = 420;
        if(a == 4) count = 0;
        if(b == 1) count = count + 100;
        if(b == 2) count = count + 57;
        if(b == 3) count = count + 70;
        if(b == 4) count = count + 0;
        if(c == 1) count = count + 130;
        if(c == 2) count = count + 160;
        if(c == 3) count = count + 118;
        if(c == 4) count = count + 0;
        if(d == 1) count = count + 167;
        if(d == 2) count = count + 266;
        if(d == 3) count = count + 75;
        if(d == 4) count = count + 0;
        System.out.println("Your total Calorie count is " + count + ".");
    }
}