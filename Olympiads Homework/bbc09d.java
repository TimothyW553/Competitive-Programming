import java.util.*;
import java.io.*;

public class bbc09d {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = readInt();
        ArrayList<Integer> lazy = new ArrayList<>();
        ArrayList<Integer> task = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            int m = readInt();
            lazy.add(m);
            task.add(m);
        }
        Collections.sort(lazy);
        Collections.sort(task, Collections.reverseOrder());
        // debugging
        long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (lazy.get(i)%10007) * (task.get(i)%10007);
            sum %= 10007;
        }
        System.out.println(sum);
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
