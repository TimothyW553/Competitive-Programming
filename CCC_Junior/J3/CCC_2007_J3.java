import java.util.*;
import java.io.*;

public class CCC_2007_J3 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] a = new int[11];
		a[1] = 100;
		a[2] = 500;
		a[3] = 1000;
		a[4] = 5000;
		a[5] = 10000;
		a[6] = 25000;
		a[7] = 50000;
		a[8] = 100000;
		a[9] = 500000;
		a[10] = 1000000;
		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			int b = Integer.parseInt(br.readLine());
			a[b] = 0;
		}
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum = sum + a[i];
		}
		double avg = 0;
		avg = sum / (10 - n);
		int offer = Integer.parseInt(br.readLine());
		if (offer > avg) {
			System.out.println("deal");
		} else {
			System.out.println("no deal");
		}
	}
}