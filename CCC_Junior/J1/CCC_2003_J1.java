import java.util.*;

public class CCC_2003_J1 {

	public static void main(String[] argument) {
		Scanner sc = new Scanner(System.in);
		int a = Integer.parseInt(sc.nextLine());
		int b = Integer.parseInt(sc.nextLine());
		int c = Integer.parseInt(sc.nextLine());
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < 2; j++) {
				System.out.print("*");
				for (int k = 0; k < b; k++) {
					System.out.print(" ");
				}
			}
			System.out.println("*");
		}
		for (int i = 0; i < 2 * b + 3; i++) {
			System.out.print("*");
		}
		System.out.println("");
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < b + 1; j++) {
				System.out.print(" ");
			}
			System.out.println("*");
		}
	}
}