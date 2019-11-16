import java.util.*;
import java.io.*;

public class ds2 {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    static final int MAX = 1000001;
    static int[] arr;
    static ArrayList<Integer> dis;

    static int find(int src) {
        if(arr[src] == src) {
            return src;
        } else {
            return arr[src] = find(arr[src]);
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = readInt();
        int m = readInt();
        arr = new int[MAX];
        dis = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            arr[i+1] = i+1;
        }
        for(int i = 0; i < m; i++) {
            int u = readInt();
            int v = readInt();
            if(find(u) != find(v)) {
                arr[find(v)] = arr[find(u)];
                dis.add(i+1);
            }
        }
        if(dis.size() != n-1) {
            System.out.println("Disconnected Graph");
        } else {
            for(int x : dis) {
                System.out.println(x);
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
4 4
1 2
1 3
2 3
3 4
 */
