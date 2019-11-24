/*
https://cses.fi/problemset/task/1675/
*/
import java.util.*;
import java.io.*;
 
public class road_reparation {
 
    static class Edge implements Comparable<Edge> {
        public int u;
        public int v;
        public int w;
        public Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
        public int compareTo(Edge other) {
            if(w >= other.w) { return 1; }
            else { return -1; }
        }
    }
 
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    static int[] dsu;
    static Edge[] roads;
    static long w = 0;
 
    static int find(int src) {
        if (dsu[src] < 0) { return src; }
        else { return dsu[src] = find(dsu[src]); }
    }
 
    static boolean join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) { return false; }
        if (dsu[u] > dsu[v]) { dsu[u] = v; }
        else {
            if (dsu[u] == dsu[v]) { dsu[u]--; }
            dsu[v] = u;
        }
        return true;
    }
 
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = readInt();
        int m = readInt();
        dsu = new int[n];
        Arrays.fill(dsu, -1);
        roads = new Edge[m];
        for (int i = 0; i < m; i++) {
            int u = readInt() - 1;
            int v = readInt() - 1;
            int w = readInt();
            roads[i] = new Edge(u, v, w);
        }
        Arrays.sort(roads);
        for (int i = 0; i < m && n > 1; i++) {
            Edge e = roads[i];
            if (join(e.u, e.v)) {
                w += e.w; n--;
            }
        }
        if (n == 1) { System.out.println(w); }
        else { System.out.println("IMPOSSIBLE"); }
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
