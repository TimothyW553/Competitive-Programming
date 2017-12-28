import java.io.*;

public class CCC_2001_J4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] grid = new int[10][10];
		int[] movex = { -1, 0, 1, 0 };
		int[] movey = { 0, 1, 0, -1 };
		int start = Integer.parseInt(br.readLine());
		int end = Integer.parseInt(br.readLine());
		int x = 4;
		int y = 4;
		int count = start;
		int dir = 2;
		grid[x][y] = count;
		count++;
		for (int z = 1; count <= end; z++) {
			for (int t = 0; t < 2 && count <= end; t++) {
				for (int a = 1; a <= z && count <= end; a++) {
					x += movex[dir];
					y += movey[dir];
					grid[x][y] = count;
					count++;
				}
				dir = (dir + 3) % 4;
			}
		}
		for (int x1 = 0; x1 < 10; x1++) {
			for (int y1 = 0; y1 < 10; y1++) {
				if (grid[x1][y1] != 0)
					System.out.print(grid[x1][y1] + " ");
			}
			System.out.println();
		}
	}
}