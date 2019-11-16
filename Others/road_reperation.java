/*
https://cses.fi/problemset/task/1675/
*/
import java.util.*;
import java.io.*;

public class road_reparation {

    static class Edge {
        public int u, v, w;
        public Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    }

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    static final int MAX = (int)Math.pow(10, 5)+1;
    static int[] arr;
    static Edge[] e;

    static int find(int src) {
        if(arr[src] == src) {
            return src;
        } else {
            return arr[src] = find(arr[src]);
        }
    }

    static boolean join(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) {
            return false;
        }
        if(arr[u] > arr[v]) {
            arr[u] = v;
        } else {
            if(arr[u] == arr[v]) {
                arr[u]--;
            }
            arr[v] = u;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = readInt();
        int m = readInt();
        arr = new int[MAX];
        Arrays.fill(arr, -1);
        e = new Edge[m];
        for(int i = 0; i < m; i++) {
            int u = readInt() - 1;
            int v = readInt() - 1;
            int w = readInt();
            e[i] = new Edge(u, v, w);
        }
        Arrays.sort(e, (i, j) -> i.w - j.w);
        int w = 0;
        for(int i = 0; i < m && n > 1; i++) {
            Edge x = e[i];
            if(join(x.u, x.v)) {
                w += x.w;
                n--;
            }
        }
        if(n == 1) {
            System.out.println(w);
        } else {
            System.out.println("IMPOSSIBLE");
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
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
 */
