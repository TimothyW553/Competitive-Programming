import java.util.Scanner;

public class CCC_2018_J4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] array = new int[N][N];
		for (int i = 0; i < array.length; i++)
			for (int j = 0; j < array.length; j++)
				array[i][j] = sc.nextInt();

		for (int k = 0; k < 4; k++) {
			boolean flag = true;
			String[] col = new String[N];
			for (int i = 0; i < col.length; i++) col[i] = "";
			
			for (int j = 0; j < N; j++)
				for (int i = N - 1; i >= 0; i--) col[j] += array[i][j] + " ";
				
			for (int i = 0; i < N; i++) {
				String[] S = col[i].split(" ");
				int[] check = new int[S.length];
				for (int j = 0; j < N; j++) {
					check[j] = Integer.parseInt(S[j]);
					array[i][j] = check[j];
				}
				for (int x = 0; x < N - 1; x++)
					if (check[x] > check[x + 1]) flag = false;

				if (array[0][0] > array[1][0]) flag = false;
			}
			if (flag == true) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++)
						System.out.print(array[i][j] + " ");
					System.out.println();
				}
				System.out.println();
				break;
			}
		}
	}
}
