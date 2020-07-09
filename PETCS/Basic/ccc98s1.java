import java.util.*;
import java.io.*;

public class ccc98s1 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        while(n-- > 0) {
            String s = br.readLine();
            String[] words = s.split(" ");
            for(String word : words) {
                if(word.length() == 4) {
                    System.out.print("**** ");
                } else {
                    System.out.print(word + " ");
                }
            }
            System.out.println();
        }
    }
}