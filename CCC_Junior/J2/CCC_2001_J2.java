import java.util.Scanner;

public class CCC_2001_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.nextLine()); //Parsing the integer is extremely important
		int m = Integer.parseInt(sc.nextLine()); //uses ParseInt every time
		for (int x = 1; x <= m; x++) {
			if ((n * x - 1) % m == 0) {
				System.out.println(x);
				return;
			}
		}
		System.out.println("No such integer exists.");
	}
}
