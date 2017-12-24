import java.util.*;

public class CCC_2016_J1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		List<String> list = new ArrayList<>();
		for (int i = 0; i < 6; i++) {
			String a = sc.nextLine();
			list.add(a);
		}
		int winning = Collections.frequency(list, "W");
		int losing = Collections.frequency(list, "L");
		if (winning == 5 || winning == 6) {
			System.out.println("1");
		}
		if (winning == 4 || winning == 3) {
			System.out.println("2");
		}
		if (winning == 1 || winning == 2) {
			System.out.println("3");
		}
		if (winning == 0 || losing == 6) {
			System.out.println("-1");
		}
	}
}