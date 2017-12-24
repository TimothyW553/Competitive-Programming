import java.util.Scanner;

public class CCC_2001_J1 {

	public static String fill(int n, char c) {
		String s = "";
		for (int x = 0; x < n; x++)
			s += c;
		return s;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int x = 1; x <= n; x += 2) {
			String s1 = fill(x, '*');
			String s2 = fill(n - x, ' ');
			System.out.println(s1 + s2 + s2 + s1);
		}
		for (int x = n - 2; x >= 1; x -= 2) {
			String s1 = fill(x, '*');
			String s2 = fill(n - x, ' ');
			System.out.println(s1 + s2 + s2 + s1);
		}
	}
}