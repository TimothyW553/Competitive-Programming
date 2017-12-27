import java.io.*;

public class CCC_2008_J3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine().trim();
		int r = 0;
		int c = 0;
		int total = 0;
		for (int x = 0; x < s.length(); x++) {
			char curr = s.charAt(x);
			int nr = 4;
			int nc = 0;
			if (curr == ' ') {
				nc = 2;
			} else if (curr == '-') {
				nc = 3;
			} else if (curr == '.') {
				nc = 4;
			} else {
				nr = (curr - 'A') / 6;
				nc = (curr - 'A') % 6;
			}
			total += Math.abs(r - nr) + Math.abs(c - nc);
			r = nr;
			c = nc;
		}
		System.out.println(total + Math.abs(r - 4) + Math.abs(c - 5));
	}
}