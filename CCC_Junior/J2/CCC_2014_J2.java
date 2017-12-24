import java.util.*;

public class CCC_2014_J2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int numVotes = Integer.parseInt(sc.nextLine());
		sc.nextLine();
		String votes = sc.nextLine();
		
		int aVotes = 0;
		int bVotes = 0;
		
		for(int i = 0; i < votes.length(); i++)
		{
			char curVote = votes.charAt(i);
			if (curVote == 'A')
				aVotes++;
			if (curVote == 'B')
				bVotes++;
		}
		
		if (aVotes > bVotes)
			System.out.println('A');
		else if (aVotes < bVotes)
			System.out.println('B');
		else
			System.out.println("Tie");
		
	}
}