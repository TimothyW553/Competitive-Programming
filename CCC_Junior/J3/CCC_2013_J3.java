import java.io.*;

public class CCC_2013_J3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		main: for (int x = Integer.parseInt(br.readLine()) + 1;; x++) {
			boolean[] nums = new boolean[10];
			int y = x;
			while (y != 0) {
				if (nums[y % 10])
					continue main;
				nums[y % 10] = true;
				y /= 10;
			}
			System.out.println(x);
			break;
		}
	}
}