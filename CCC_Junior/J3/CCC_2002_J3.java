import java.io.*;

public class CCC_2002_J3 {
	public static void main(String[] args) throws NumberFormatException, IOException  {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int c1 = Integer.parseInt(br.readLine());
		int c2 = Integer.parseInt(br.readLine());
		int c3 = Integer.parseInt(br.readLine());
		int c4 = Integer.parseInt(br.readLine());
		int total = Integer.parseInt(br.readLine());
		int min = 10000;
		int count = 0;
		for (int x = 0; x <= total / c1; x++) {
			for (int y = 0; y <= total / c2; y++) {
				for (int z = 0; z <= total / c3; z++) {
					for (int i = 0; i <= total / c4; i++) {
						if (x * c1 + y * c2 + z * c3 + i * c4 == total) {
							System.out.println("# of PINK is " + x + " # of GREEN is " + y + " # of RED is " + z
									+ " # of ORANGE is " + i);
							count++;
							if (x + y + z + i < min) min = x + y + z + i;
						}
					}
				}
			}
		}
		System.out.println("Total combinations is " + count);
		System.out.println("Minimum number of tickets to print is " + min);
	}
}
