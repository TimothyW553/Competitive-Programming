import java.io.*;

public class CCC_2003_J4 {
	static String vowels = "aeiouAEIOU ";

	public static String getLast(String s) {
		String result = "";
		for (int x = s.length() - 1; x >= 0; x--) {
			char c = s.charAt(x);
			if (vowels.indexOf(c) >= 0)
				return (result + c).toLowerCase();
			result += c;
		}
		return result.toLowerCase();
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = Integer.parseInt(br.readLine()); t > 0; t--) {
			String s1 = getLast(br.readLine());
			String s2 = getLast(br.readLine());
			String s3 = getLast(br.readLine());
			String s4 = getLast(br.readLine());
			if (s1.equals(s2) && s2.equals(s3) && s3.equals(s4))
				System.out.println("perfect");
			else if (s1.equals(s2) && s3.equals(s4))
				System.out.println("even");
			else if (s1.equals(s3) && s2.equals(s4))
				System.out.println("cross");
			else if (s1.equals(s4) && s3.equals(s2))
				System.out.println("shell");
			else
				System.out.println("free");
		}
	}
}