import java.io.*;
import java.util.*;

public class CCC_2018_J1 {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int first = sc.nextInt();
        int second = sc.nextInt();
        int third = sc.nextInt();
        int fourth = sc.nextInt();
        if((first == 8 || first == 9) && (fourth == 8 || fourth == 9) && second == third){
            System.out.println("ignore");
        } else {
            System.out.println("answer");
        }
    }
}
