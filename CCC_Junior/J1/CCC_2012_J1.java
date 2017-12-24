import java.util.*;

public class CCC_2012_J1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int limit = sc.nextInt();
		int speed = sc.nextInt();
		if (speed <= limit)
			System.out.println("Congratulations, you are within the speed limit!");
		int over = speed - limit;
		if (over >= 1 && over <= 20)
			System.out.println("You are speeding and your fine is $100.");
		if (over >= 21 && over <= 30)
			System.out.println("You are speeding and your fine is $270.");
		if (over > 30)
			System.out.println("You are speeding and your fine is $500.");
	}
}