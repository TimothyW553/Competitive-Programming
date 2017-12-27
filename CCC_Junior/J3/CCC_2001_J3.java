import java.util.*;
import java.io.*;

public class CCC_2001_J3 {
	
	static String[] suits = { "Clubs", "Diamonds", "Hearts", "Spades" };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine().trim();
		ArrayList<ArrayList<Character>> hands = new ArrayList<ArrayList<Character>>();
		for (int x = 0; x < 4; x++)
			hands.add(new ArrayList<Character>());
		int count = 0;
		for (int x = 0; x < input.length(); x++) {
			char curr = input.charAt(x);
			if (curr == 'C')
				count = 0;
			else if (curr == 'D')
				count = 1;
			else if (curr == 'H')
				count = 2;
			else if (curr == 'S')
				count = 3;
			else
				hands.get(count).add(curr);
		}
		System.out.println("Cards Dealt Points");
		int total = 0;
		for (int x = 0; x < 4; x++) {
			System.out.print(suits[x] + " ");
			int points = 0;
			int size = hands.get(x).size();
			for (int y = 0; y < size; y++) {
				char curr = hands.get(x).get(y);
				System.out.print(curr + " ");
				if (curr == 'A')
					points += 4;
				else if (curr == 'K')
					points += 3;
				else if (curr == 'Q')
					points += 2;
				else if (curr == 'J')
					points += 1;
			}
			if (size == 0)
				points += 3;
			else if (size == 1)
				points += 2;
			else if (size == 2)
				points += 1;
			System.out.println(points);
			total += points;
		}
		System.out.println("Total " + total);
	}
}
