import java.util.*;

public class K {

    public static int[][] multMatrix(int[][] m1, int[][] m2, int i, int j, int res[][]) {
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] m1 = new int[n][m];
        int[][] m2 = new int[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                m1[i][j] = sc.nextInt();
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                m2[i][j] = sc.nextInt();
            }
        }
        int[][] ans = new int[n][m];
    }
}
