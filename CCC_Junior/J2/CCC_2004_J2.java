import java.util.Scanner;

public class CCC_2004_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int start = sc.nextInt();
		int end = sc.nextInt();
		for (int x = start; x <= end; x++) {
			if ((start - x) % 60 == 0)
				System.out.println("All positions change in year " + x);
		}
	}
}