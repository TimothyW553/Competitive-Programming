import java.awt.*;
import java.util.*;

public class CCC_2005_J4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int[][] board = new int[b][a];
		int width = sc.nextInt();
		int length = sc.nextInt();
		int steps = sc.nextInt();
		for (int x = 0; x < board.length; x++) {
			for (int y = 0; y < board[x].length; y++) {
				board[x][y] = 1;
				if ((x < length && y < width) || (x < length && y > board[x].length - width - 1)
						|| (x > board.length - length - 1 && y < width)
						|| (x > board.length - length - 1 && y > board[x].length - width - 1)) {
					board[x][y] = 0;
				}
			}
		}
		Point location = new Point();
		for (int x = 0; x < board.length;) {
			for (int y = 0; y < board[x].length; y++) {
				if (board[x][y] == 1) {
					location = new Point(y, x);
					board[(int) location.getY()][(int) location.getX()] = 0;
					break;
				}
			}
			break;
		}
		String direction = "right";
		for (int z = steps; z > 0; z--) {
			if (direction.equals("right")) {
				// UP
				if (location.getY() - 1 >= 0 && board[(int) location.getY() - 1][(int) location.getX()] == 1) {
					location.setLocation(location.getX(), location.getY() - 1);
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "up";
					continue;
				}
				// RIGHT
				else if (location.getX() + 1 < board[0].length
						&& board[(int) location.getY()][(int) location.getX() + 1] == 1) {
					location.setLocation(location.getX() + 1, location.getY());
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "right";
					continue;
				}
				// DOWN
				else if (location.getY() + 1 < board.length
						&& board[(int) location.getY() + 1][(int) location.getX()] == 1) {
					location.setLocation(location.getX(), location.getY() + 1);
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "down";
					continue;
				}

				// LEFT
				else if (location.getX() - 1 >= 0 && board[(int) location.getY()][(int) location.getX() - 1] == 1) {
					location.setLocation(location.getX() - 1, location.getY());
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "left";
					continue;
				}
			} else if (direction.equals("down")) {
				// RIGHT
				if (location.getX() + 1 < board[0].length
						&& board[(int) location.getY()][(int) location.getX() + 1] == 1) {
					location.setLocation(location.getX() + 1, location.getY());
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "right";
					continue;
				}
				// DOWN
				else if (location.getY() + 1 < board.length
						&& board[(int) location.getY() + 1][(int) location.getX()] == 1) {
					location.setLocation(location.getX(), location.getY() + 1);
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "down";
					continue;
				}
				// LEFT
				else if (location.getX() - 1 >= 0 && board[(int) location.getY()][(int) location.getX() - 1] == 1) {
					location.setLocation(location.getX() - 1, location.getY());
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "left";
					continue;
				}
				// UP
				else if (location.getY() - 1 >= 0 && board[(int) location.getY() - 1][(int) location.getX()] == 1) {
					location.setLocation(location.getX(), location.getY() - 1);
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "up";
					continue;
				}
			} else if (direction.equals("left")) {
				// DOWN
				if (location.getY() + 1 < board.length
						&& board[(int) location.getY() + 1][(int) location.getX()] == 1) {
					location.setLocation(location.getX(), location.getY() + 1);
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "down";
					continue;
				}
				// LEFT
				else if (location.getX() - 1 >= 0 && board[(int) location.getY()][(int) location.getX() - 1] == 1) {
					location.setLocation(location.getX() - 1, location.getY());
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "left";
					continue;
				}
				// UP
				else if (location.getY() - 1 >= 0 && board[(int) location.getY() - 1][(int) location.getX()] == 1) {
					location.setLocation(location.getX(), location.getY() - 1);
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "up";
					continue;
				}
				// RIGHT
				else if (location.getX() + 1 < board[0].length
						&& board[(int) location.getY()][(int) location.getX() + 1] == 1) {
					location.setLocation(location.getX() + 1, location.getY());
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "right";
					continue;
				}
			} else if (direction.equals("up")) {
				// LEFT
				if (location.getX() - 1 >= 0 && board[(int) location.getY()][(int) location.getX() - 1] == 1) {
					location.setLocation(location.getX() - 1, location.getY());
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "left";
					continue;
				}
				// UP
				if (location.getY() - 1 >= 0 && board[(int) location.getY() - 1][(int) location.getX()] == 1) {
					location.setLocation(location.getX(), location.getY() - 1);
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "up";
					continue;
				}
				// RIGHT
				else if (location.getX() + 1 < board[0].length
						&& board[(int) location.getY()][(int) location.getX() + 1] == 1) {
					location.setLocation(location.getX() + 1, location.getY());
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "right";
					continue;
				}
				// DOWN
				else if (location.getY() + 1 < board.length
						&& board[(int) location.getY() + 1][(int) location.getX()] == 1) {
					location.setLocation(location.getX(), location.getY() + 1);
					board[(int) location.getY()][(int) location.getX()] = 0;
					direction = "down";
					continue;
				}

			}

		}
		System.out.println((int) location.getX() + 1);
		System.out.println((int) location.getY() + 1);
	}
}