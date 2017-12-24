import java.util.*;

public class CCC_2011_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int humidity = Integer.parseInt(sc.nextLine());
		int time = Integer.parseInt(sc.nextLine());
		boolean inTime = false;
		int timeToLand = 0;
		for (int i = 1; i <= time; i++) {
			int altitude = (int) ((humidity * Math.pow(i, 3)) + (2 * Math.pow(i, 2)) + i - (6 * Math.pow(i, 4)));
			if (altitude <= 0) {
				inTime = true;
				timeToLand = i;
				break;
			}
		}
		if(inTime) {
			System.out.println("The balloon first touches ground at hour: ");
			System.out.println(timeToLand);
		} else {
			System.out.println("The balloon does not touch ground in the given time.");
		}
	}
}