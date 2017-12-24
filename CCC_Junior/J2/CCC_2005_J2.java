import java.util.Scanner;

public class CCC_2005_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int count = 0;
		for (int i = a; i <= b; i++) {
			int count2 = 2;
			for (int j = 2; j < i; j++) {
				if (i % j == 0)
					count2++;
				if (count2 > 4)
					break;
			}
			if (count2 == 4)
				count++;
		}
		System.out.println("The number of RSA numbers between " + a + " and " + b + " is " + count);
	}
}
