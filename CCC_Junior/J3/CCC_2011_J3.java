import java.io.*;

public class CCC_2011_J3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x1 = Integer.parseInt(br.readLine());
		int x2 = Integer.parseInt(br.readLine());
		int s = 2;
		while (x1 >= x2) {
			int temp = x1 - x2;
			x1 = x2;
			x2 = temp;
			s++;
		}
		System.out.println(s);
	}
}