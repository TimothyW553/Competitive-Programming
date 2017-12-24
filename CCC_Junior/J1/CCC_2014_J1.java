import java.util.*;

public class CCC_2014_J1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		double c = sc.nextDouble();
		if (a == 60 && b == 60 && c == 60 && a + b + c == 180) {
			System.out.println("Equilateral");
		}
		if (a != b && a != c && b != a && b != c && c != a && a != b && a + b + c == 180) {
			System.out.println("Scalene");
		}
		if (a == b && a != c && b != c && a + b + c == 180) {
			System.out.println("Isosceles");
		}
		if (b == c && b != a && c != a && a + b + c == 180) {
			System.out.println("Isosceles");
		}
		if (c == a && c != b && a != b && a + b + c == 180) {
			System.out.println("Isosceles");
		}
		if (a + b + c != 180) {
			System.out.println("Error");
		}
	}
}