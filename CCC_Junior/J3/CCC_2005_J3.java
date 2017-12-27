import java.util.*;
import java.io.*;

public class CCC_2005_J3 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<String[]> locations = new ArrayList<String[]>();
		String d = "";
		String location = "";
		while (!location.equals("SCHOOL")) {
			d = br.readLine().trim();
			location = br.readLine().trim();
			locations.add(new String[] { d, location });
		}
		for (int x = locations.size() - 1; x >= 0; x--)
			if (!locations.get(x)[1].equals("SCHOOL")) {
				System.out.printf("Turn %s %s\n", locations.get(x + 1)[0].equals("R") ? "LEFT" : "RIGHT",
						"onto " + locations.get(x)[1] + " street.");
			}
		System.out.println("Turn " + (locations.get(0)[0].equals("R") ? "LEFT" : "RIGHT") + " into your HOME.");
	}
}