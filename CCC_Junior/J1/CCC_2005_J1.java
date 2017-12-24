import java.util.*;

public class CCC_2005_J1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int n = sc.nextInt();
		int w = sc.nextInt();
		double a = Math.max(0, d - 100) * 25 + 15 * n + 20 * w;
		double b = Math.max(0, d - 250) * 45 + 35 * n + 25 * w;
		// double c = a / 10;
		// double d2 = b / 10;
		System.out.println("Plan A costs " + a / 100);
		System.out.println("Plan B costs " + b / 100);
		if (a < b)
			System.out.println("Plan A is cheapest.");
		else if (a == b)
			System.out.println("Plan A and B are the same price.");
		else
			System.out.println("Plan B is cheapest.");

	}
}