import java.io.*;

public class CCC_2002_J3{
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int pink = Integer.parseInt(in.readLine());
		int green = Integer.parseInt(in.readLine());
		int red = Integer.parseInt(in.readLine());
		int orange = Integer.parseInt(in.readLine());
		int desiredAmount = Integer.parseInt(in.readLine());
		int min = 99999, combination = 0;
		int tp = 0, tg = 0, tr = 0, to = 0;
		
		for(int i=0;i<=desiredAmount/pink;i++){
			tp = i * pink;
			for(int j=0;j<=desiredAmount/green;j++){
				tg = j * green;
				for(int k=0;k<=desiredAmount/red;k++){
					tr = k * red;
					for(int f=0;f<=desiredAmount/orange;f++){
						to = f * orange;
						if(tp+tg+tr+to == desiredAmount){
							combination++;
							if(i+j+k+f < min){
								min = i+j+k+f;
							}
							System.out.println("# of PINK is "+i+" # of GREEN is "
							+j+" # of RED is "+k+" # of ORANGE is "+f);
						}
					}
				}
			}
		}
		System.out.println("Total combinations is "+combination+".");
		System.out.println("Minimum number of tickets to print is "+min+".");
	}

}
