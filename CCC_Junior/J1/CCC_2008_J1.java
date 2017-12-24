import java.util.*;

public class CCC_2008_J1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		double w = sc.nextDouble();
		double h = sc.nextDouble();
		double BMI = (w) / (h * h);

		if (BMI > 25)
			System.out.println("Overweight");
		if (BMI >= 18.5 && BMI <= 25.0)
			System.out.println("Normal weight");
		if (BMI < 18.5)
			System.out.println("Underweight");
	}
}