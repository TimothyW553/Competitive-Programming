import java.util.*;
import java.io.*;

public class CCC_2011_J4 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		boolean[][] vis = new boolean[401][200];
		vis[200][0] = vis[200][1] = vis[200][2] = vis[201][2] =
		vis[202][2] = vis[203][2] = vis[203][3] = vis[203][4] =
		vis[204][4] = vis[205][4] = vis[205][3] = vis[205][2] =
		vis[206][2] = vis[207][2] = vis[207][3] = vis[207][4] =
		vis[207][5] = vis[207][6] = vis[206][6] = vis[205][6] =
		vis[204][6] = vis[203][6] = vis[202][6] = vis[201][6] =
		vis[200][6] = vis[199][6] = vis[199][5] = vis[199][4] = true;

		int x = 199, y = 4;

		while(true) {
			String dir = in.next();
			int dist = in.nextInt();

			int xDir = 0, yDir = 0;
			switch(dir) {
				case "u":
					yDir = -1;
					break;
				case "r":
					xDir = +1;
					break;
				case "d":
					yDir = +1;
					break;
				case "l":
					xDir = -1;
					break;
				case "q":
					return;
			}

			String state = "safe";
			while(dist --> 0) {
				if(vis[x += xDir][y += yDir])
					state = "DANGER";
				vis[x][y] = true;
			}

			System.out.println((x-200)+" "+(-y-1)+" "+state);
			if(state.equals("DANGER"))
				break;
		}
	}
}
