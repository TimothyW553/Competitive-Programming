import java.util.*;

public class CCC_2007_J1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		int mx = Math.max(Math.max(a, b), c);
		int mn = Math.min(Math.min(a, b), c);
		int md = a ^ b ^ c ^ mx ^ mn;
		
		System.out.println(md);
	}
}