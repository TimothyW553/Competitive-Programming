import java.io.*;
import java.util.*;

public class CCC_2008_J4 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String next = "";
		while (!(next = br.readLine().trim()).equals("0")) {
			String[] e = new StringBuilder(next).reverse().toString().split(" ");
			Stack<String> s = new Stack<String>();
			int i = 0;
			String result = "";
			do {
				if (!isOperator(e[i])) {
					s.push(e[i]);
				} else {
					String s1 = s.pop();
					String s2 = s.pop();
					result = s1 + " " + s2 + " " + e[i];
					s.push(result);
				}
				i++;
			} while (s.size() >= 0 && i < e.length);
			System.out.println(result);
		}
	}

	private static boolean isOperator(String s) {
		if (s.equals("+") || s.equals("-"))
			return true;
		return false;
	}
}