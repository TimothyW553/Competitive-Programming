import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        boolean flag = false;
        int index = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == '.') {
                flag = true;
                index = i;
                break;
            }
        }
        if(flag) {
            String format = "";
            String fileName = "";
            for(int i = index+1; i < str.length(); i++) {
                format += str.charAt(i);
            }
            for(int i = 0; i < index; i++) {
                fileName += str.charAt(i);
            }
            System.out.println("\"" + fileName + "\" - " + format);
        } else {
            String format = sc.nextLine();
            System.out.println("\"" + str + "\" - " + format.toLowerCase());
        }
    }
}
