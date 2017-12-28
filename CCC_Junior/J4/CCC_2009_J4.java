import java.util.*;

public class CCC_2009_J4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int w = sc.nextInt();

		Stack<String> words = new Stack();
		words.add("TODAY");
		words.add("LUCK");
		words.add("GOOD");
		words.add("CCC");
		words.add("TO");
		words.add("WELCOME");

		while (!words.empty()) {
			int wordletters = 0;
			ArrayList<String> line = new ArrayList();

			while (words.peek().length() + wordletters + line.size() <= w) {
				wordletters += words.peek().length();
				line.add(words.pop());
				if (words.empty())
					break;
			}

			int spaces = w - wordletters;
			while (spaces > 0) {
				for (int i = 0; i < Math.max(1, line.size() - 1) && spaces > 0; i++) {
					line.set(i, line.get(i) + ".");
					spaces--;
				}
			}

			for (String i : line) {
				System.out.print(i);
			}
			System.out.println();
		}

	}

}