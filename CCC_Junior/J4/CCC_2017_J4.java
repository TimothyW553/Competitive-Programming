import java.util.Scanner;

public class CCC_2017_J4 {

	public static int numTimes = 31;
	public static int fTimes[] = { 34, 111, 123, 135, 147, 159, 210, 222, 234, 246, 258, 321, 333, 345, 357, 420, 432,
			444, 456, 531, 543, 555, 630, 642, 654, 741, 753, 840, 852, 951, 1111 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int D = sc.nextInt();

		int numFavourite = numTimes * (D / 720);
		D %= 720;

		int time = D / 60 * 100 + D % 60;

		for (int i = 0; i < numTimes; i++) {
			if (time >= fTimes[i]) {
				numFavourite++;
			} else {
				break;
			}
		}
		System.out.println(numFavourite);
	}
}