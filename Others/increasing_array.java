import java.util.*;
import java.io.*;

public class increasing_array {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    static long[] arr;
    static final int MAX = (int)(2*Math.pow(10, 5));
    static long count = 0;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        long n = readLong() - 1;
        long x = readLong();
        for(int i = 0; i < n; i++) {
            long y = readLong();
            if(x > y) {
                count += (x-y);
            } else {
                x = y;
            }
        }
        System.out.println(count);
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
/*
5
3 2 5 1 7
 */
