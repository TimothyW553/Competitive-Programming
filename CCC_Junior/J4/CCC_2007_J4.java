import java.util.Arrays;
import java.util.Scanner;

public class CCC_2007_J4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s1 = sc.nextLine().replaceAll("\\s+", "").toCharArray();
		char[] s2 = sc.nextLine().replaceAll("\\s+", "").toCharArray();
		Arrays.sort(s1);
		Arrays.sort(s2);
		for (int x = 0; x < s1.length; x++) {
			if (s1[x] != s2[x]) {
				System.out.println("Is not an anagram.");
				return;
			}
		}
		System.out.println("Is an anagram.");

	}

}