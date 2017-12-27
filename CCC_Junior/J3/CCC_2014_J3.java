import java.io.*;
import java.util.Scanner;

public class CCC_2014_J3 {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int antonia = 100;
		int david = 100;
		for (int x = 0; x < n; x++) {
			int a = sc.nextInt();
			int d = sc.nextInt();
			if (a > d)
				david -= a;
			else if (a < d)
				antonia -= d;
		}
		System.out.println(antonia);
		System.out.println(david);
	}
}