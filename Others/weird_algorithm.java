/*
https://cses.fi/problemset/task/1068
 */
import java.util.*;
import java.io.*;

public class weird_algorithm {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        long n = readLong();
        System.out.print(n + " ");
        while(n != 1) {
            if(n % 2 == 0) {
                n /= 2;
            } else {
                n *= 3; n += 1;
            }
            System.out.print(n + " ");
        }
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong () throws IOException {
        return Long.parseLong(next());
    }

    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter () throws IOException {
        return next().charAt(0);
    }

    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}
