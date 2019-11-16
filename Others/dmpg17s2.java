import java.util.*;
import java.io.*;

public class dmpg17s2 {

    static final int MAX = (int)Math.pow(10, 5)+1;
    static int[] cities;
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;

    static int find(int src) { // union find
        if(cities[src] == src) {
            return src;
        } else {
            return cities[src] = find(cities[src]); // store - reduce recomputing
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        cities = new int[MAX];
        int n = readInt();
        int q = readInt();
        for(int i = 0; i < n; i++) {
            cities[i+1] = i+1;
        }
        for(int i = 0; i < q; i++) {
            char cmd = readCharacter();
            int x = readInt();
            int y = readInt();
            if(cmd == 'A') {
                x = find(x);
                y = find(y);
                cities[x] = y;
            } else if(cmd == 'Q') {
                if(find(x) == find(y)) {
                    System.out.println("Y");
                } else {
                    System.out.println("N");
                }
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
/*
5 6
A 1 2
A 2 3
Q 1 3
A 1 5
Q 5 2
Q 4 1
 */
