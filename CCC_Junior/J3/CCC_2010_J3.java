import java.util.Scanner;

public class CCC_2010_J3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = 0, b = 0;
		int input = sc.nextInt();
		while (input != 7) {
			String next = "";
			String next1 = "";
			switch (input) {

			case 1:
				next = sc.next();
				if (next.equals("A"))
					a = sc.nextInt();
				else if (next.equals("B"))
					b = sc.nextInt();
				break;
			case 2:
				next = sc.next();
				if (next.equals("A"))
					System.out.println(a);
				else if (next.equals("B"))
					System.out.println(b);
				break;
			case 3:
				next = sc.next();
				next1 = sc.next();
				if (next.equals("A") && next1.equals("B"))
					a += b;
				else if (next.equals("B") && next1.equals("A"))
					b += a;
				else if (next.equals("A") && next1.equals("A"))
					a += a;
				else if (next.equals("B") && next1.equals("B"))
					b += b;
				break;
			case 4:
				next = sc.next();
				next1 = sc.next();
				if (next.equals("A") && next1.equals("B"))
					a *= b;
				else if (next.equals("B") && next1.equals("A"))
					b *= a;
				else if (next.equals("A") && next1.equals("A"))
					a *= a;
				else if (next.equals("B") && next1.equals("B"))
					b *= b;
				break;
			case 5:
				next = sc.next();
				next1 = sc.next();
				if (next.equals("A") && next1.equals("B"))
					a -= b;
				else if (next.equals("B") && next1.equals("A"))
					b -= a;
				else if (next.equals("A") && next1.equals("A"))
					a -= a;
				else if (next.equals("B") && next1.equals("B"))
					b -= b;
				break;
			case 6:
				next = sc.next();
				next1 = sc.next();
				if (next.equals("A") && next1.equals("B"))
					a /= b;
				else if (next.equals("B") && next1.equals("A"))
					b /= a;
				else if (next.equals("A") && next1.equals("A"))
					a /= a;
				else if (next.equals("B") && next1.equals("B"))
					b /= b;
				break;
			}
			input = sc.nextInt();
		}
	}
}