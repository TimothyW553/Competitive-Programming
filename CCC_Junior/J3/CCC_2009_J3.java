import java.io.*;

public class CCC_2009_J3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String time = br.readLine().trim();
		if (time.length() < 4)
			time = "0000" + time;
		int l = time.length();
		int hour = Integer.parseInt(time.substring(l - 4, l - 2));
		int minutes = Integer.parseInt(time.substring(l - 2, l));
		System.out.printf("%s%02d in Ottawa\n", hour == 0 ? "" : hour, minutes);
		hour = (hour + 21) % 24;

		System.out.printf("%s%02d in Victoria\n", hour == 0 ? "" : hour, minutes);
		hour = (hour + 1) % 24;

		System.out.printf("%s%02d in Edmonton\n", hour == 0 ? "" : hour, minutes);
		hour = (hour + 1) % 24;

		System.out.printf("%s%02d in Winnipeg\n", hour == 0 ? "" : hour, minutes);
		hour = (hour + 1) % 24;

		System.out.printf("%s%02d in Toronto\n", hour == 0 ? "" : hour, minutes);
		hour = (hour + 1) % 24;

		System.out.printf("%s%02d in Halifax\n", hour == 0 ? "" : hour, minutes);
		if (minutes + 30 >= 60)
			hour = (hour + 1) % 24;

		minutes = (minutes + 30) % 60;
		System.out.printf("%d%02d in St. John\'s\n", hour == 0 ? "" : hour, minutes);
	}
}