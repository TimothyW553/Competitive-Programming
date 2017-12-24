import java.util.*;

public class CCC_2012_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = Integer.parseInt(sc.nextLine());
		int b = Integer.parseInt(sc.nextLine());
		int c = Integer.parseInt(sc.nextLine());
		int d = Integer.parseInt(sc.nextLine());

		if (a == b && b == c && c == d)
			System.out.println("Fish At Constant Depth");
		else if (a < b && b < c && c < d)
			System.out.println("Fish Rising");
		else if (a > b && b > c && c > d)
			System.out.println("Fish Diving");
		else
			System.out.println("No Fish");

	}
}