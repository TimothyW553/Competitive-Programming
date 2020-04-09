import java.util.*;

public class J {

    public static int[][] sumMatrix(int[][] m1, int[][] m2, int i, int j, int[][] res) {
        if(j >= m1[0].length) { // on the last row
            return res;
        }
        res[i][j] = m1[i][j] + m2[i][j];
        i++;
        if(i == m1.length) {
            i = 0;
            j++;
        }
        return sumMatrix(m1, m2, i, j, res);
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
        sumMatrix(m1, m2, 0, 0, ans);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }
    }
}
