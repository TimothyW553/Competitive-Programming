import java.util.Scanner;

public class CCC_2002_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = "";
		String cons = "bcdfghjklmnpqrstvwxyz";
		while (!(s = sc.nextLine()).equals("quit!")) {
			int l = s.length();
			if (l > 4 && s.substring(l - 2).equals("or") && cons.indexOf(s.charAt(l - 3)) != -1)
				System.out.println(s.substring(0, l - 2) + "our");
			else
				System.out.println(s);
		}
	}
}