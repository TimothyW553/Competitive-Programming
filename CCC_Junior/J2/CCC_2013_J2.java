import java.util.Scanner;

public class CCC_2013_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.nextLine();

		if (s.matches("[IOSHZXN]*")) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}

	}

}