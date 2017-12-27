import java.io.*;

public class CCC_2012_J3 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int K = Integer.parseInt(br.readLine());
		char[][] pattern = new char[][] { { '*', 'x', '*' }, { ' ', 'x', 'x' }, { '*', ' ', '*' } };

		for (int x = 0; x < 3 * K; x++) {
			for (int y = 0; y < 3 * K; y++) {
				System.out.print(pattern[x / K][y / K]);
			}
			System.out.println();
		}
	}
}