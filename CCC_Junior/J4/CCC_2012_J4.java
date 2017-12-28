import java.util.Scanner;

public class CCC_2012_J4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		String s = sc.next();
		for (int i = 0; i < s.length(); i++) {
			int ascii = s.charAt(i) - ((i + 1) * 3 + k);
			if (ascii < (int) 'A') {
				ascii += 26;
			}
			System.out.print((char) ascii);
		}
	}

}