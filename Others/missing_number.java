/*
https://cses.fi/problemset/task/1083/
 */
import java.util.*;
import java.io.*;

public class missing_number {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = readInt();
        arr = new int[n+2];
        Arrays.fill(arr, -1);
        for(int i = 0; i < n-1; i++) {
            int m = readInt();
            arr[m] = m;
        }
//        for(int x : arr) {
//            System.out.println(x);
//        }
        for(int i = 1; i <= n; i++) {
            if(arr[i] == -1) {
                System.out.println(i);
            }
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
