import java.util.*;

public class CCC_2008_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int b = Integer.parseInt(sc.nextLine());
		int n = Integer.parseInt(sc.nextLine());
		String s = "ABCDE";
		while (b != 4 || n != 1) {
			for (int x = 0; x < n; x++) {
				if (b == 1) {
					s = s.substring(1) + s.charAt(0);
				} else if (b == 2) {
					s = "" + s.charAt(4) + s.substring(0, 4);
				} else if (b == 3) {
					s = "" + s.charAt(1) + s.charAt(0) + s.substring(2);
				}
			}
			b = Integer.parseInt(sc.nextLine());
			n = Integer.parseInt(sc.nextLine());
		}
		for (int x = 0; x < s.length(); x++)
			System.out.print(s.charAt(x) + " ");
	}
}