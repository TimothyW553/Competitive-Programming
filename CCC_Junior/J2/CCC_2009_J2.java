import java.util.*;

public class CCC_2009_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = Integer.parseInt(sc.nextLine());
		int b = Integer.parseInt(sc.nextLine());
		int c = Integer.parseInt(sc.nextLine());
		int n = Integer.parseInt(sc.nextLine());
		int count = 0;
		for (int x = 0; x <= n / a; x++) {
			for (int y = 0; y <= n / b; y++) {
				for (int z = 0; z <= n / c; z++) {
					if (x * a + y * b + z * c <= n && x + y + z > 0) {
						System.out.println(x + " Brown Trout," + y + "Northern Pike," + z + " Yellow Pickerel");
						count++;
					}
				}
			}
		}
		System.out.println("Number of ways to catch fish: " + count);
	}
}