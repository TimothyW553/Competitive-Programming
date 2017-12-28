import java.util.*;

public class CCC_2013_J4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int time = sc.nextInt();
		int[] chores = new int[sc.nextInt()];
		for (int x = 0; x < chores.length; x++)
			chores[x] = sc.nextInt();
		Arrays.sort(chores);
		int count = 0;
		for (int i = 0; i < chores.length; i++) {
			if (time >= chores[i]) {
				time -= chores[i];
				count++;
			} else
				break;
		}
		System.out.println(count);
	}

}