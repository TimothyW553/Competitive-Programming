/*
 * Duowei OJ - 1053: MPI Maelstorm
 */
 
import java.util.*;
 
public class Main {
 
    public static int node;
    public static int adj[][];
    public static int dijkstra[];
    public static boolean vis[];
    public final static int INF = 0x3f3f3f3f;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        adj = new int[n][n];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                String str = sc.next();
                if(str.equals("x")) {
                    adj[i][j] = INF;
                    adj[j][i] = INF;
                } else {
                    adj[i][j] = Integer.parseInt(str);
                    adj[j][i] = Integer.parseInt(str);
                }
            }
        }
        dijkstra = new int[n];
        Arrays.fill(dijkstra, INF);
        dijkstra[0] = 0;
        vis = new boolean[n];
        int count = 0;
        while(count < n) {
            int min = INF;
            int idx = 0;
            for(int i = 0; i < n; i++) {
                if(!vis[i] && dijkstra[i] < min) {
                    min = dijkstra[i];
                    idx = i;
                }
            }
            for(int i = 0; i < n; i++) {
                if(!vis[i] && dijkstra[idx] + adj[idx][i] < dijkstra[i]) {
                    dijkstra[i] = dijkstra[idx] + adj[idx][i];
                }
            }
            vis[idx] = true;
            count++;
        }
        int max = -1;
        for(int i = 0; i < n; i++) {
            max = Math.max(dijkstra[i], max);
        }
        System.out.println(max);
    }
}
