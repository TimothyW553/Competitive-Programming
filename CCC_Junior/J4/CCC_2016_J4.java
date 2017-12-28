import java.io.*;

public class CCC_2016_J4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] time = br.readLine().split(":");
		int min = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
		int travelTime = 240;
		for (int i = 0; i < (travelTime + 1) / 2; i++, min++) {
			if (7 * 60 <= min && min < 10 * 60) {
				travelTime++;
			} else if (15 * 60 <= min && min < 19 * 60) {
				travelTime++;
			}
		}
		min %= 1440;
		System.out.printf("%02d:%02d\n", min / 60, min % 60);

		System.out.close();
	}
}