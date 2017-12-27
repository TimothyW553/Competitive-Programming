import java.io.*;

public class CCC_2006_J3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String alpha = "abc def ghi jkl mno pqrstuv wxyz";
		String next = "";
		while (!(next = br.readLine().trim()).equals("halt")) {
			int total = alpha.indexOf(next.charAt(0)) % 4 + 1;
			for (int x = 1; x < next.length(); x++) {
				if (next.charAt(x) / 4 == next.charAt(x - 1) / 4)
					total += 2;
				total += alpha.indexOf(next.charAt(x)) % 4 + 1;
			}
			System.out.println(total);
		}
	}
}