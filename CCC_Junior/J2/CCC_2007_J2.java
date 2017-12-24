import java.util.*;

public class CCC_2007_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = "";
		do {
			s = sc.nextLine();
			if (s.equals("CU")) {
				System.out.println("see you");
			}
			if (s.equals(":-)")) {
				System.out.println("I'm happy");
			}
			if (s.equals(":-(")) {
				System.out.println("I'm unhappy");
			}
			if (s.equals(";-)")) {
				System.out.println("wink");
			}
			if (s.equals("(~.~)")) {
				System.out.println("sleepy");
			}
			if (s.equals("TA")) {
				System.out.println("totally awesome");
			}
			if (s.equals("CCC")) {
				System.out.println("Canadian Computing Competition");
			}
			if (s.equals("CUZ")) {
				System.out.println("because");
			}
			if (s.equals("TY")) {
				System.out.println("thank-you");
			}
			if (s.equals("TTYL")) {
				System.out.println("talk to you later");
			}
			if (!(s.equals("CU") || s.equals(":-)") || s.equals(":-(") || s.equals(";-)") || s.equals("(~.~)")
					|| s.equals("TA") || s.equals("CCC") || s.equals("CUZ") || s.equals("TY") || s.equals("TTYL"))) {
				System.out.println(s);
			}
		} while (!(s.equals("TTYL")));
	}
}