import java.io.*;

public class CCC_2015_J3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// abcdefgh ijklmn opqrstu vwxyz
		String vowel = "aeiou";
		char[] closest = { 'a', 'a', 'a', 'e', 'e', 'e', 'e', 'i', 'i', 'i', 'i', 'i', 'o', 'o', 'o', 'o', 'o', 'o',
				'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u' };
		char[] next = { 'b', 'c', 'd', 'f', 'f', 'g', 'h', 'j', 'j', 'k', 'l', 'm', 'n', 'p', 'p', 'q', 'r', 's', 't',
				'v', 'v', 'w', 'x', 'y', 'z', 'z' };
		char[] in = br.readLine().toCharArray();
		String res = "";
		for (int x = 0; x < in.length; x++) {
			if (vowel.indexOf(in[x]) == -1)
				res += "" + in[x] + (char) (closest[in[x] - 'a']) + (char) (next[in[x] - 'a']);
			else
				res += in[x];

		}
		System.out.println(res);
	}
}