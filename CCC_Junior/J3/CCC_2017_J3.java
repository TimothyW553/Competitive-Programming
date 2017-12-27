import java.io.*;

public class CCC_2017_J3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] a = br.readLine().split(" ");
		String[] b = br.readLine().split(" ");
		int x = Integer.parseInt(br.readLine());
		int dis = Math.abs(Integer.parseInt(b[0]) - Integer.parseInt(a[0]))
				+ Math.abs(Integer.parseInt(b[1]) - Integer.parseInt(a[1]));
		if (x < dis) {
			System.out.println("N");
		}
		 else if ((x - dis) % 2 == 0) {
			System.out.println("Y");
		} else {
			System.out.println("N");
		}
	}

}