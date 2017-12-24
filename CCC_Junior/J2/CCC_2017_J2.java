import java.util.Scanner;

public class CCC_2017_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int k = sc.nextInt();
		int a = 0;
		int sum = 0;
		int b = 10;
		for (int i = 0; i < k; i++) {
			a = N * b;
			sum = sum + a;
			b = b * 10;
		}
		System.out.println(sum + N);
	}
}