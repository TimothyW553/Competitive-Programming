import java.util.*;
import java.io.*;

public class hkccc15j4 {

    static class Pair implements Comparable<Pair>{
        public int first;
        public int second;
        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
        public int compareTo(Pair other) {
            if(first >= other.first) {
                return 1;
            } else {
                return -1;
            }
        }
    }

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    static ArrayList<Pair> ar;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        int l = readInt();
        int n = readInt();
        ar = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            int x = readInt();
            int y = readInt();
            ar.add(new Pair(x, y));
        }
        Collections.sort(ar);
        int max = -1;
        int ans = 0;
        for(Pair x : ar) {
            max = Math.max(max,x.first - ans);
            ans = Math.max(ans,x.second);
        }
        max = Math.max(max, l - ans);
        System.out.println(max);
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
