import java.util.Scanner;

public class CCC_2006_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int count = 0;
		for (int i = 1; i < 10; i++) {
			if (a >= i && b >= (10 - i))
				count++;
		}
		
		if (count == 1)
			System.out.println("There is " + count + " way to get the sum 10.");
		if (count > 1)
			System.out.println("There are " + count + " ways to get the sum 10.");
		if (count >= 10)
			System.out.println("There are 0 ways to get the sum 10.");
		if (count == 0)
			System.out.println("There are 0 ways to get the sum 10.");
	}
}