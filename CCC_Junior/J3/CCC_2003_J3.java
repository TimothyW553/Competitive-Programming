import java.io.*;

public class CCC_2003_J3 {
	public static int checkMove(int square) {
		switch (square) {
		case 9:
			square = 34;
			break;
		case 54:
			square = 19;
			break;
		case 40:
			square = 64;
			break;
		case 90:
			square = 48;
			break;
		case 67:
			square = 86;
			break;
		case 99:
			square = 77;
			break;
		}
		return square;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int square = 1;
		int dice = Integer.parseInt(br.readLine());
		while (dice != 0) {
			if (dice + square <= 100) {
				square += dice;
				square = checkMove(square);
			}
			System.out.println("You are now on square " + square);
			if (square == 100)
				break;
			dice = Integer.parseInt(br.readLine());
		}
		System.out.println(square == 100 ? "You Win!" : "You Quit!");
	}
}