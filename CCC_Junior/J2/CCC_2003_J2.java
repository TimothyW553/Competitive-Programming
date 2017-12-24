import java.util.*;

public class CCC_2003_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = 0;
		while ((n = Integer.parseInt(sc.nextLine())) != 0) {
			int last = 0;
			for (int x = 1; x * x <= n; x++) {
				if (n % x == 0)
					last = x;
			}
			int perimeter = 2 * last + 2 * (n / last);
			System.out.println("Minimum perimeter is " + perimeter + " with dimensions " + last + " x " + (n / last));
		}
	}
}