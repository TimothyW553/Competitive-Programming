import java.util.*;

public class CCC_2004_J4 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		char[] encodeKey = sc.nextLine().toCharArray();
		char[] temp = sc.nextLine().toCharArray();
		List<Character> preEncode = new ArrayList<Character>();
		List<Character> postEncode = new ArrayList<Character>();
		for (char a : temp) {
			if (alphabet.indexOf(a) != -1) {
				preEncode.add(a);
			}
		}
		int counter = 0;
		for (int x = 0; x < preEncode.size(); x++) {
			int indexPreEncode = alphabet.indexOf(preEncode.get(x));
			int moveLength = alphabet.indexOf(encodeKey[counter]);

			postEncode.add((alphabet.charAt((indexPreEncode + moveLength) % 26)));
			counter = (counter + 1) % encodeKey.length;
		}
		for (char a : postEncode) {
			System.out.print(a);
		}
	}
}