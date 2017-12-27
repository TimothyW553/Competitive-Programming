import java.io.*;

//This is where TimothyW553 begins to use BufferedReader
public class CCC_2004_J3 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n1 = Integer.parseInt(br.readLine());
		int n2 = Integer.parseInt(br.readLine());
		String[] s = new String[n1];
		for (int x = 0; x < n1; x++)
			s[x] = br.readLine().trim();

		for (int x = 0; x < n2; x++) {
			String st = br.readLine().trim();
			for (String i : s)
				System.out.println(i + " as " + st);
		}
	}
}
