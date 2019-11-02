import java.util.*;

public class ccc16s3 {

    static final int MAX = 100001;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static boolean[] pho = new boolean[MAX];
    static boolean[] valid = new boolean[MAX];
    static boolean[] vis = new boolean[MAX];
    static int[] dist = new int[MAX];
    static int diamater = 0;

    static void dfs(int u) {
        for(int v : graph.get(u)) {
            if(!vis[v] && valid[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                dfs(v);
            }
        }
    }

    static boolean search(int u, int parent) {
        if(pho[u]) {
            valid[u] = true;
        }
        for(int v : graph.get(u)) {
            if(v != parent) {
                valid[u] |= search(v, u);
            }
        }
        return valid[u];
    }

    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for(int i = 0; i < m; i++) {
            int r = sc.nextInt();
            pho[r] = true;
        }

        for(int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i < n-1; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            graph.get(x).add(y);
            graph.get(y).add(x);
        }

        for(int i = 0; i < n; i++) {
            if(pho[i]) {
                search(i, -1);
                break;
            }
        }

        int count = n;
        Arrays.fill(vis, false);
        int src = 0;
        for(int i = 0; i < n; i++) {
            if(valid[i]) {
                src = i;
                break;
            }
        }
        dist[src] = 0;
        vis[src] = true;
        dfs(src);

        for(int i = src; i < n; i++) {
            if(valid[i] && dist[i] > dist[n]) {
                src = i;
            }
        }
        Arrays.fill(vis, false);
        dist[src] = 0;
        vis[src] = true;
        dfs(src);

        for(int i = 0; i < n; i++) {
            if(valid[i]) {
                diamater = Math.max(diamater, dist[i]);
            } else {
                count--;
            }
        }

        System.out.println((2 * (count - 1) - diamater));
    }
}
